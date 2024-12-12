/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:22:00 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/12 01:51:08 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_map	*create_stack_map(int x, int y, int z)
{
	t_map *new;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z * 2;
	new->rx = new->x;
	new->ry = new->y;
	new->rz = new->z;
	new->color = NULL;
	new->next = NULL;
	return (new);
}

void	rotate_z(t_map *map)
{
	double	tmp;

	tmp = map->rx;
	map->rx = tmp * cos(GAMMA) - map->ry * sin(GAMMA);
	map->ry = tmp * sin(GAMMA) + map->ry * cos(GAMMA);
}

void	rotate_y(t_map *map)
{
	double tmp;

	tmp = map->rx;
	map->rx = tmp * cos(TETHA) + map->rz * sin(TETHA);
	map->rz = map->rz * cos(TETHA) - tmp * sin(TETHA);
}

void	rotate_x(t_map *map)
{
	double	tmp;

	tmp = map->ry;
	map->ry = tmp * cos(ALPHA) - map->rz * sin(ALPHA);
	map->rz = tmp * sin(ALPHA) + map->rz * cos(ALPHA);
}

void	rotate_map(t_map **map, void (f)(t_map*), void (d)(t_map*), void (g)(t_map*))
{
	t_map *tmp;

	if (!(*map))
		return ;
	tmp = (*map);
	while (tmp)
	{
		f(tmp);
		d(tmp);
		g(tmp);
		tmp = tmp->next;
	}
}

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