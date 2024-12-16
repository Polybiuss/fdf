/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:40:07 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/16 03:56:01 by jbergos          ###   ########.fr       */
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

double	iso_project_x(double x, double y, int zoom)
{
	return ((x - y) * cos(ANGLE)) * (ZOOM + zoom) + WIDTH / 2;
}

double	iso_project_y(double x, double y, double z, int zoom)
{
	return (((x + y) * sin(ANGLE) - z)) * (ZOOM + zoom) + HEIGTH / 2;
}

// double win_width(t_map *map, t_map_len *len)
// {
// 	return (rotate_zx((map->x - len->width / 2), (map->y - len->heigth /2) ,len->gamma) * ZOOM + WIDTH / 2);
// }

// double	win_heigth(t_map *map, t_map_len *len)
// {
// 	return (rotate_zy((map->x - len->width / 2), (map->y - len->heigth /2), len->gamma) * ZOOM + HEIGTH / 2);
// }
double	cabinet_project_x(double x, double z, int zoom)
{
	double factor;

	factor = 0.5;
	return (x - z * factor * cos(0.785398)) * (ZOOM + zoom) + WIDTH / 2;
}

double	cabinet_project_y(double y, double z, int zoom)
{
	double factor;

	factor = 0.5;
	return (y - z * factor * cos(0.785398)) * (ZOOM + zoom) + HEIGTH / 2;
}

double	parallel_projection_x(double x, int zoom)
{
	return (x * (ZOOM + zoom) + WIDTH / 3);
}

double	parrallel_projection_y(double y, double z, int zoom)
{
	return ((y * (ZOOM + zoom) + HEIGTH / 3) - z);
}

double	wich_projection_x(t_map_len *map, double x, double y, double z)
{
	if (map->projection == 0)
		return (iso_project_x(x, y ,map->zoom));
	else if (map->projection == 1)
		return (cabinet_project_x(x, z, map->zoom));
	else
		return (parallel_projection_x(x, map->zoom));
}

double	wich_projection_y(t_map_len *map, double x, double y, double z)
{
	if (map->projection == 0)
		return (iso_project_y(x, y, z, map->zoom));
	else if (map->projection == 1)
		return (cabinet_project_y(y, z, map->zoom));
	else
		return (parrallel_projection_y(y, z, map->zoom));
}
void	projection_s(t_map *map, t_map_len *map_len, t_line *line)
{
	double	prj_x;
	double	prj_y;
	double	prj_z;
	double	tmp;
	prj_x = (map_len->scalex + map->x - map_len->width /2) * cos(map_len->gamma) - (map_len->scaley + map->y - map_len->heigth / 2) * sin(map_len->gamma);
	prj_y = (map_len->scalex + map->x - map_len->width / 2) * sin(map_len->gamma) + (map_len->scaley + map->y - map_len->heigth / 2) * cos(map_len->gamma);
	//
	prj_z = (map->z * map_len->high) * cos(map_len->theta) - prj_x * sin(map_len->theta);
	prj_x = prj_x * cos(map_len->theta) + (map->z * map_len->high) * sin(map_len->theta);
	//
	tmp = prj_y;
	prj_y = tmp * cos(map_len->alpha) - prj_z * sin(map_len->alpha);
	prj_z = tmp * sin(map_len->alpha) + prj_z * cos(map_len->alpha);
	line->x = prj_x /** (ZOOM + map_len->zoom) */ - map_len->scalex / 2 + wich_projection_x(map_len, prj_x, prj_y, prj_z);
	line->y = prj_y /** (ZOOM + map_len->zoom) */ - map_len->scaley / 2 + wich_projection_y(map_len, prj_x, prj_y, prj_z);

}

void	projection_e(t_map *map, t_map_len *map_len, t_line *line)
{
	double	prj_x;
	double	prj_y;
	double	prj_z;
	double	tmp;
	prj_x = (map_len->scalex + map->x - map_len->width /2) * cos(map_len->gamma) - (map_len->scaley + map->y - map_len->heigth / 2) * sin(map_len->gamma);
	prj_y = (map_len->scalex + map->x - map_len->width / 2) * sin(map_len->gamma) + (map_len->scaley + map->y - map_len->heigth / 2) * cos(map_len->gamma);
	//
	prj_z = (map->z * map_len->high) * cos(map_len->theta) - prj_x * sin(map_len->theta);
	prj_x = prj_x * cos(map_len->theta) + (map->z * map_len->high) * sin(map_len->theta);
	//
	tmp = prj_y;
	prj_y = tmp * cos(map_len->alpha) - prj_z * sin(map_len->alpha);
	prj_z = tmp * sin(map_len->alpha) + prj_z * cos(map_len->alpha);
	line->xe = prj_x /** (ZOOM + map_len->zoom) */ - map_len->scalex / 2 + wich_projection_x(map_len, prj_x, prj_y, prj_z);
	line->ye = prj_y /** (ZOOM + map_len->zoom) */ - map_len->scaley / 2 + wich_projection_y(map_len, prj_x, prj_y, prj_z);

}

t_line	create_line_plus(t_map *start, t_map *end, t_map_len *map)
{
	t_line	line;
	projection_s(start, map, &line);
	projection_e(end, map, &line);
	line.dx = abs(line.xe - line.x);
	line.dy = abs(line.ye - line.y);
	line.z = start->z;
	line.ze = end->z;
	line.sx = (line.x < line.xe) ? 1 : -1;
	line.sy = (line.y < line.ye) ? 1 : -1;
	line.err = line.dx - line.dy;
	return (line);
}

int	ratio_gradient_color_x(int s_color, int e_color, t_line line)
{
	float ratio;
	int color;
	if (line.xd == line.xe)
		return (s_color);
	ratio = ((float)line.x - (float)line.xd) / ((float)line.xe - (float)line.xd);
	color = (interpolate((s_color >> 24) & 0xFF, (e_color >> 24) & 0xFF, ratio) << 24) |
		(interpolate((s_color >> 16) & 0xFF, (e_color >> 16) & 0xFF, ratio) << 16) |
		(interpolate((s_color >> 8) & 0xFF, (e_color >> 8) & 0xFF, ratio) << 8) |
		(interpolate(s_color & 0xFF, e_color & 0xFF, ratio));
	return (color);
}

int	ratio_gradient_color_y(int s_color, int e_color, t_line line)
{
	float ratio;
	int color;
	
	if (line.yd == line.ye)
		return (s_color);
	ratio = ((float)line.y - (float)line.yd) / ((float)line.ye - (float)line.yd);
	color = (interpolate((s_color >> 24) & 0xFF, (e_color >> 24) & 0xFF, ratio) << 24) |
		(interpolate((s_color >> 16) & 0xFF, (e_color >> 16) & 0xFF, ratio) << 16) |
		(interpolate((s_color >> 8) & 0xFF, (e_color >> 8) & 0xFF, ratio) << 8) |
		(interpolate(s_color & 0xFF, e_color & 0xFF, ratio));
	return (color);
}

int	gradient_color(t_map *start, t_map *end, t_line line)
{
	int	dx;
	int	dy;
	int color;

	dx = line.xe - line.x;
	dy = line.ye - line.y;
	if (abs(dx) > abs(dy))
		color = ratio_gradient_color_x(start->color, end->color, line);
	else
		color = ratio_gradient_color_y(start->color, end->color, line);
	return (color);
}


void	draw_line_plus(t_fdf *fdf, t_map *start, t_map *end, t_map_len *map)
{
	t_line	line;
	int e2;

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
	fdf->map_len = map;
	render_map_plus(fdf->map_len, fdf);
	loop_render(fdf);
}