/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:40:07 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/12 00:26:25 by jbergos          ###   ########.fr       */
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
	// ft_printf("here\n");
	return (NULL);
}

double	iso_project_x(t_map *map)
{
	return ((map->rx - map->ry) * cos(ANGLE));
}

double	iso_project_y(t_map *map)
{
	return ((map->rx + map->ry) * sin(ANGLE) - map->rz);
}

double win_width(t_map *map, t_map_len *len)
{
	return ((map->rx - len->width / 2) * ZOOM + WIDTH / 2);
}

double	win_heigth(t_map *map, t_map_len *len)
{
	return ((map->ry - len->heigth /2) * ZOOM + HEIGTH / 2);
}

t_line	create_line_plus(t_map *start, t_map *end, t_map_len *map)
{
	t_line	line;
	line.x = win_width(start, map) + iso_project_x(start);
	line.y = win_heigth(start, map) + iso_project_y(start);
	line.xe = win_width(end, map) + iso_project_x(end);
	line.ye = win_heigth(end, map) + iso_project_y(end);
	line.dx = abs(line.xe - line.x);
	line.dy = abs(line.ye - line.y);
	line.sx = (line.x < line.xe) ? 1 : -1;
	line.sy = (line.y < line.ye) ? 1 : -1;
	line.err = line.dx - line.dy;
	return (line);
}

void	draw_line_plus(t_fdf *fdf, t_map *start, t_map *end, t_map_len *map)
{
	t_line	line;
	int e2;

	line = create_line_plus(start, end, map);
	while (1)
	{
		my_mlx_pixel_put(fdf, line.x, line.y, 0x00FF0000);
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

	// if (!map->map)
		// return ;
	tmp = map->map;
	while (tmp)
	{
		// ft_printf("yolo\n");
		hoz = find_map_plus(map->map, tmp->x + 1, tmp->y);
			if (hoz)
				draw_line_plus(fdf, tmp, hoz, map);
		vert = find_map_plus(map->map, tmp->x, tmp->y + 1);
			if (vert)
				draw_line_plus(fdf, tmp, vert, map);
		tmp = tmp->next;
	}
}

void	render_map_plus(t_map_len *map, t_fdf *fdf)
{
	line_map_plus(map, fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void	make_render_plus(t_map_len *map)
{
	t_fdf *fdf;
	
	fdf = init_render();
	if (!fdf)
		return ;
	render_map_plus(map, fdf);
	loop_render(map, fdf);
}