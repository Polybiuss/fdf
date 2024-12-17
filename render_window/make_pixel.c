/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:37:59 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 02:26:33 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x > WIDTH || y > HEIGTH || x < 0 || y < 0)
		return ;
	dst = fdf->addr + (y * fdf->ll + x * (fdf->bpp / 8));
	*(unsigned int *)dst = color;
}

t_line	create_line_plus(t_map *start, t_map *end, t_map_len *map)
{
	t_line	line;

	rotate_s(start, map, &line);
	rotate_e(end, map, &line);
	line.dx = abs(line.xe - line.x);
	line.dy = abs(line.ye - line.y);
	line.z = start->z;
	line.ze = end->z;
	if (line.x < line.xe)
		line.sx = 1;
	else
		line.sx = -1;
	if (line.y < line.ye)
		line.sy = 1;
	else
		line.sy = -1;
	line.err = line.dx - line.dy;
	return (line);
}
