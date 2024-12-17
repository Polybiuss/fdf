/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 01:56:26 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 02:20:08 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double	iso_project_x(double x, double y, int zoom)
{
	return (((x - y) * cos(ANGLE)) * (ZOOM + zoom) + WIDTH / 2);
}

double	cabinet_project_x(double x, double z, int zoom)
{
	double	factor;

	factor = 0.5;
	return ((x - z * factor * cos(0.785398)) * (ZOOM + zoom) + WIDTH / 2);
}

double	parallel_projection_x(double x, int zoom)
{
	return (x * (ZOOM + zoom) + WIDTH / 3);
}

double	wich_projection_x(t_map_len *map, double x, double y, double z)
{
	if (map->projection == 0)
		return (iso_project_x(x, y, map->zoom));
	else if (map->projection == 1)
		return (cabinet_project_x(x, z, map->zoom));
	else if (map->projection == 2)
		return (parallel_projection_x(x, map->zoom));
	else
		return (x * (ZOOM + map->zoom) + WIDTH / 2);
}
