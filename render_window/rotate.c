/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 02:07:27 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 02:24:09 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rotate_s(t_map *map, t_map_len *map_len, t_line *line)
{
	double	prj_x;
	double	prj_y;
	double	prj_z;
	double	tmp;

	prj_x = (map_len->scalex + map->x - map_len->width / 2)
		* cos(map_len->gamma) - (map_len->scaley + map->y - map_len->heigth / 2)
		* sin(map_len->gamma);
	prj_y = (map_len->scalex + map->x - map_len->width / 2)
		* sin(map_len->gamma) + (map_len->scaley + map->y - map_len->heigth / 2)
		* cos(map_len->gamma);
	prj_z = (map->z * map_len->high) * cos(map_len->theta) - prj_x
		* sin(map_len->theta);
	prj_x = prj_x * cos(map_len->theta) + (map->z * map_len->high)
		* sin(map_len->theta);
	tmp = prj_y;
	prj_y = tmp * cos(map_len->alpha) - prj_z * sin(map_len->alpha);
	prj_z = tmp * sin(map_len->alpha) + prj_z * cos(map_len->alpha);
	line->x = wich_projection_x(map_len, prj_x, prj_y, prj_z);
	line->y = wich_projection_y(map_len, prj_x, prj_y, prj_z);
}

void	rotate_e(t_map *map, t_map_len *map_len, t_line *line)
{
	double	prj_x;
	double	prj_y;
	double	prj_z;
	double	tmp;

	prj_x = (map_len->scalex + map->x - map_len->width / 2)
		* cos(map_len->gamma) - (map_len->scaley + map->y - map_len->heigth / 2)
		* sin(map_len->gamma);
	prj_y = (map_len->scalex + map->x - map_len->width / 2)
		* sin(map_len->gamma) + (map_len->scaley + map->y - map_len->heigth / 2)
		* cos(map_len->gamma);
	prj_z = (map->z * map_len->high) * cos(map_len->theta) - prj_x
		* sin(map_len->theta);
	prj_x = prj_x * cos(map_len->theta) + (map->z * map_len->high)
		* sin(map_len->theta);
	tmp = prj_y;
	prj_y = tmp * cos(map_len->alpha) - prj_z
		* sin(map_len->alpha);
	prj_z = tmp * sin(map_len->alpha) + prj_z
		* cos(map_len->alpha);
	line->xe = wich_projection_x(map_len, prj_x, prj_y, prj_z);
	line->ye = wich_projection_y(map_len, prj_x, prj_y, prj_z);
}
