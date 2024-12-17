/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:21:50 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 21:57:22 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

int	width_map(t_map *map)
{
	t_map	*tmp;
	int		i;

	i = 0;
	tmp = map;
	while (tmp)
	{
		if (tmp->x != i)
			break ;
		++i;
		tmp = tmp->next;
	}
	return (i);
}

int	heigth_map(t_map *map)
{
	t_map	*tmp;
	int		i;

	i = 0;
	tmp = map;
	while (tmp)
	{
		i = tmp->y + 1;
		tmp = tmp->next;
	}
	return (i);
}

t_map_len	*create_map_len(t_map *map)
{
	t_map_len	*map_len;

	if (!map)
		return (NULL);
	map_len = malloc(sizeof(t_map_len));
	if (!map_len)
		return (NULL);
	map_len->width = width_map(map);
	map_len->heigth = heigth_map(map);
	map_len->alpha = 0.0;
	map_len->gamma = 0.0;
	map_len->theta = 0.0;
	map_len->scalex = 0;
	map_len->scaley = 0;
	map_len->high = 1.0;
	map_len->map = map;
	map_len->zoom = 1;
	map_len->projection = 0;
	return (map_len);
}

int	main(int argc, char *argv[])
{
	t_map_len	*map;

	if (argc == 2)
	{
		map = create_map_len(parse_map(argv[1]));
		if (!map)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		make_render_plus(map);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
