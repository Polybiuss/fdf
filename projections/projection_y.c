/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 01:57:30 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 02:18:11 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double	iso_project_y(double x, double y, double z, int zoom)
{
	return ((((x + y) * sin(ANGLE) - z)) * (ZOOM + zoom) + HEIGTH / 2);
}

double	cabinet_project_y(double y, double z, int zoom)
{
	double	factor;

	factor = 0.5;
	return ((y - z * factor * cos(0.785398)) * (ZOOM + zoom) + HEIGTH / 2);
}

double	parrallel_projection_y(double y, double z, int zoom)
{
	return ((y * (ZOOM + zoom) + HEIGTH / 3) - z);
}

double	wich_projection_y(t_map_len *map, double x, double y, double z)
{
	if (map->projection == 0)
		return (iso_project_y(x, y, z, map->zoom));
	else if (map->projection == 1)
		return (cabinet_project_y(y, z, map->zoom));
	else if (map->projection == 2)
		return (parrallel_projection_y(y, z, map->zoom));
	else
		return (y * (ZOOM + map->zoom) + HEIGTH / 2);
}
