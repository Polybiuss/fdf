/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:37:59 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/09 17:05:54 by jbergos          ###   ########.fr       */
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
