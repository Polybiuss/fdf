/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:09:45 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 02:14:09 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	color_by_u_char(int heigth, int dft, int border)
{
	float	ratio;
	int		color;

	ratio = abs(heigth) / 5.0f;
	color = \
		(interpolate((dft >> 24) & 0xFF, (border >> 24) & 0xFF, ratio) << 24)
		| (interpolate((dft >> 16) & 0xFF, (border >> 16) & 0xFF, ratio) << 16)
		| (interpolate((dft >> 8) & 0xFF, (border >> 8) & 0xFF, ratio) << 8)
		| interpolate(dft & 0xFF, border & 0xFF, ratio);
	return (color);
}

int	color_for_heigth(int heigth)
{
	if (heigth == 0)
		return (C_DF);
	else if (heigth > 5)
		return (C_H);
	else if (heigth < -5)
		return (C_B);
	else if (heigth > 0)
		return (color_by_u_char(heigth, C_DF, C_H));
	else
		return (color_by_u_char(heigth, C_DF, C_B));
}

int	ratio_gradient_color_x(int s_c, int e_c, t_line line)
{
	float	cf;
	int		color;

	if (line.xd == line.xe)
		return (s_c);
	cf = ((float)line.x - (float)line.xd) / ((float)line.xe - (float)line.xd);
	color = (interpolate((s_c >> 24) & 0xFF, (e_c >> 24) & 0xFF, cf) << 24)
		| (interpolate((s_c >> 16) & 0xFF, (e_c >> 16) & 0xFF, cf) << 16)
		| (interpolate((s_c >> 8) & 0xFF, (e_c >> 8) & 0xFF, cf) << 8)
		| (interpolate(s_c & 0xFF, e_c & 0xFF, cf));
	return (color);
}

int	ratio_gradient_color_y(int s_c, int e_c, t_line line)
{
	float	cf;
	int		color;

	if (line.yd == line.ye)
		return (s_c);
	cf = ((float)line.y - (float)line.yd) / ((float)line.ye - (float)line.yd);
	color = (interpolate((s_c >> 24) & 0xFF, (e_c >> 24) & 0xFF, cf) << 24)
		| (interpolate((s_c >> 16) & 0xFF, (e_c >> 16) & 0xFF, cf) << 16)
		| (interpolate((s_c >> 8) & 0xFF, (e_c >> 8) & 0xFF, cf) << 8)
		| (interpolate(s_c & 0xFF, e_c & 0xFF, cf));
	return (color);
}

int	gradient_color(t_map *start, t_map *end, t_line line)
{
	int	dx;
	int	dy;
	int	color;

	dx = line.xe - line.x;
	dy = line.ye - line.y;
	if (abs(dx) > abs(dy))
		color = ratio_gradient_color_x(start->color, end->color, line);
	else
		color = ratio_gradient_color_y(start->color, end->color, line);
	return (color);
}
