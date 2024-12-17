/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:40:07 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 02:25:46 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_map	*find_map_plus(t_map *map, int x, int y)
{
	t_map	*find;

	if (!map)
		return (NULL);
	find = map;
	while (find)
	{
		if (find->x == x && find->y == y)
			return (find);
		find = find->next;
	}
	return (NULL);
}

void	draw_line_plus(t_fdf *fdf, t_map *start, t_map *end, t_map_len *map)
{
	t_line	line;
	int		e2;

	line = create_line_plus(start, end, map);
	line.xd = line.x;
	line.yd = line.y;
	while (1)
	{
		my_mlx_pixel_put(fdf, line.x, line.y, gradient_color(start, end, line));
		if (line.x == line.xe && line.y == line.ye)
			break ;
		e2 = 2 * line.err;
		if (e2 > -line.dy)
		{
			line.err -= line.dy;
			line.x += line.sx;
		}
		if (e2 < line.dx)
		{
			line.err += line.dx;
			line.y += line.sy;
		}
	}
}

void	line_map_plus(t_map_len *map, t_fdf *fdf)
{
	t_map	*tmp;
	t_map	*hoz;
	t_map	*vert;

	tmp = map->map;
	while (tmp)
	{
		hoz = find_map_plus(map->map, tmp->x + 1, tmp->y);
		if (hoz)
			draw_line_plus(fdf, tmp, hoz, map);
		vert = find_map_plus(map->map, tmp->x, tmp->y + 1);
		if (vert)
			draw_line_plus(fdf, tmp, vert, map);
		tmp = tmp->next;
	}
}

void	render_map_plus(t_fdf *fdf)
{
	line_map_plus(fdf->map_len, fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void	make_render_plus(t_map_len *map)
{
	t_fdf	*fdf;

	fdf = init_render();
	if (!fdf)
		return ;
	fdf->map_len = map;
	render_map_plus(fdf);
	loop_render(fdf);
}
