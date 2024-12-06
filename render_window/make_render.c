/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:42:40 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/06 22:10:00 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	point_map(t_map **map, t_fdf *fdf)
{
	t_map *tmp;

	if (!(*map))
		return ;
	tmp = (*map);
	while (tmp)
	{
		my_mlx_pixel_put(fdf, tmp->posx, tmp->posy, 0x00FF0000);
		tmp = tmp->next;
	}

}

t_map	*find_map(t_map **map, int x, int y)
{
	t_map	*find;

	if (!(*map))
		return (NULL);
	find = (*map);
	while (find)
	{
		if (find->x == x && find->y == y)
			return (find);
		find = find->next;
	}
	return (NULL);
}

void	draw_line(t_fdf *fdf, t_map *start, t_map *end)
{
	int dx = abs(end->posx - start->posx);
	int dy = abs(end->posy - start->posy);
	int sx = (start->posx < end->posx) ? 1 : -1;
	int	sy = (start->posy < end->posy) ? 1 : -1;
	int err = dx - dy;
	int x = start->posx;
	int y = start->posy;

	while (1)
	{
		my_mlx_pixel_put(fdf, x, y, 0x00FF0000);
		if (x == end->posx && y == end->posy)
			break ;
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y += sy;
		}
	}
}

void	line_map(t_map **map, t_fdf *fdf)
{
	t_map	*tmp;
	t_map	*hoz;
	t_map	*vert;
	(void)fdf;
	if (!(*map))
		return ;
	tmp = (*map);
	while (tmp)
	{
		hoz = find_map(map, tmp->x + 1, tmp->y);
			if (hoz)
				draw_line(fdf, tmp, hoz);	
		vert = find_map(map, tmp->x, tmp->y + 1);
			if (vert)
				draw_line(fdf, tmp, vert);
		tmp = tmp->next;
	}
}

void	render_map(t_map **map, t_fdf *fdf)
{
	point_map(map, fdf);
	line_map(map, fdf);
}

void	make_render(t_map **map)
{
	t_fdf *fdf;

	fdf = init_render();
	if (!fdf)
		return ;
	render_map(map, fdf);
	loop_render(fdf);
}