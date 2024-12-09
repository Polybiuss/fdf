/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:42:40 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/09 18:07:02 by jbergos          ###   ########.fr       */
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

t_line	create_line(t_map *start, t_map *end)
{
	t_line	line;

	line.dx = abs(end->posx - start->posx);
	line.dy = abs(end->posy - start->posy);
	line.sx = (start->posx < end->posx) ? 1 : -1;
	line.sy = (start->posy < end->posy) ? 1 : -1;
	line.err = line.dx - line.dy;
	line.x = start->posx;
	line.y = start->posy;
	return (line);
}

void	draw_line(t_fdf *fdf, t_map *start, t_map *end)
{

	t_line	line;
	int	e2;

	line = create_line(start, end);
	while (1)
	{
		my_mlx_pixel_put(fdf, line.x, line.y, 0x00FF0000);
		if (line.x == end->posx && line.y == end->posy)
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
	// point_map(map, fdf);
	line_map(map, fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
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