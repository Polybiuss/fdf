/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:22:00 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/16 01:51:42 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

unsigned char	interpolate(unsigned char start, unsigned char end, float ratio)
{
	return (unsigned char)(start + ratio * (end - start));
}

int	color_by_u_char(int heigth, int dft, int border)
{
	float ratio;
	int color;

	ratio = abs(heigth) / 5.0f;
	color = (interpolate((dft >> 24) & 0xFF, (border >> 24) & 0xFF, ratio) << 24) |
		(interpolate((dft >> 16) & 0xFF, (border >> 16) & 0xFF, ratio) << 16) |
		(interpolate((dft >> 8) & 0xFF, (border >> 8) & 0xFF, ratio) << 8) |
		interpolate(dft & 0xFF, border & 0xFF, ratio);
	return (color);
}

int	color_for_heigth(int heigth)
{
	if (heigth == 0)
		return (C_DF);
	else if (heigth > 5)
		return (C_H);
	else if  (heigth < -5)
		return (C_B);
	else if (heigth > 0)
		return (color_by_u_char(heigth, C_DF, C_H));
	else
		return (color_by_u_char(heigth, C_DF, C_B));
}

t_map	*create_stack_map(int x, int y, int z)
{
	t_map *new;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	new->color = color_for_heigth(new->z);
	new->next = NULL;
	return (new);
}

// void	rotate_z(t_map *map, double gamma)
// {
// 	double	tmp;

// 	tmp = map->rx;
// 	map->rx = tmp * cos(gamma) - map->ry * sin(gamma);
// 	map->ry = tmp * sin(gamma) + map->ry * cos(gamma);
// }

// double	rotate_zx(double x, double y, double gamma)
// { 
// 	return (x * cos(gamma) - y * sin(gamma));
// }


// double	rotate_zy(double x, double y, double gamma)
// {
// 	return (x *sin(gamma) + y * cos(gamma));
// }

// void	rotate_y(t_map *map)
// {
// 	double tmp;

// 	tmp = map->rx;
// 	map->rx = tmp * cos(TETHA) + map->rz * sin(TETHA);
// 	map->rz = map->rz * cos(TETHA) - tmp * sin(TETHA);
// }

// void	rotate_x(t_map *map)
// {
// 	double	tmp;

// 	tmp = map->ry;
// 	map->ry = tmp * cos(ALPHA) - map->rz * sin(ALPHA);
// 	map->rz = tmp * sin(ALPHA) + map->rz * cos(ALPHA);
// }

// void	rotate_map(t_map **map, void (f)(t_map*, double), double angle)
// {
// 	t_map *tmp;

// 	if (!(*map))
// 		return ;
// 	tmp = (*map);
// 	while (tmp)
// 	{
// 		f(tmp, angle);
// 		tmp = tmp->next;
// 	}
// }

void	map_add_back(t_map **head, t_map *back)
{
	t_map	*tmp;

	if (!(*head))
	{
		*head = back;
		return ;
	}
	tmp = (*head);
	while (tmp)
	{
		if (!tmp->next)
			break;
	tmp = tmp->next;
	}
	tmp->next = back;
}

void	free_table(char **pptr)
{
	int i;

	i = 0;
	while (pptr[i])
	{
		free(pptr[i]);
		++i;
	}
	free(pptr);
}

void	create_map(t_map **map, char *str, int y)
{
	char	**pptr;
	int		x;

	x = 0;
	pptr = ft_split_scam(str, " \n");
	while (pptr[x])
	{
		map_add_back(map, create_stack_map(x, y, ft_atoi(pptr[x])));
		++x;
	}
	free_table(pptr);
}