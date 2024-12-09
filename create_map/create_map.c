/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:22:00 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/09 18:45:53 by jbergos          ###   ########.fr       */
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
	new->z = z;
	new->rotatex = new->x * cos(ROTATION) - new->y * cos(ROTATION);
	new->rotatey = new->x * sin(ROTATION) + new->y * cos(ROTATION);
	new->xp = SCALE * ((new->x - new->rotatey) * (cos(ANGLE)));
	new->yp = SCALE * ((new->x + new->rotatey) * sin(ANGLE) - new->z);
	new->posx = (new->rotatex * ZOOM + WIDTH / 2) + new->xp;
	new->posy = (new->rotatey * ZOOM + HEIGTH / 2) + new->yp;
	new->next = NULL;
	return (new);
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