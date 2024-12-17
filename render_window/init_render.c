/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:23:21 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 02:06:50 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_hook(int kc, t_fdf *fdf)
{
	if (kc == 65307)
		quit(fdf);
	if (kc == 119 || kc == 115 || kc == 97 || kc == 100)
		scale_hook(fdf, kc);
	if ((kc >= 65361 && kc <= 65364) || kc == 44 || kc == 46)
		rotate_hook(fdf, kc);
	if (kc == 65293)
		reset_hook(fdf);
	if (kc == 45 || kc == 61 || kc == 57 || kc == 48)
		zoom_n_high_hook(fdf, kc);
	if (kc == 65506)
		projection_hook(fdf);
	return (0);
}

t_fdf	*init_render(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGTH, "fdf");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
	return (fdf);
}

void	loop_render(t_fdf *fdf)
{
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
	mlx_loop(fdf->mlx);
	quit(fdf);
}
