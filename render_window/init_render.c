/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:23:21 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/12 01:52:08 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "../mlx_linux/mlx_int.h"

int	key_hook(int keycode, t_fdf *fdf)
{
	(void) fdf;
	printf("Key: %d\n", keycode);
	if (keycode == 65307)
		quit(fdf);
	if(keycode == 65361)
		{
			
		}
	return (0);
}

int	close_window(t_fdf *fdf)
{
	quit(fdf);
	return (0);
}

void	quit(t_fdf *fdf)
{
	if (fdf)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
		free(fdf);
	}
	exit(0);
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
	// mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return (fdf);
}

void	loop_render(t_map_len *map, t_fdf *fdf)
{
	// t_fdf	*fdf;

	(void)map;	
	// printf("longueur %d\n", map->heigth);
	// fdf = init_render();
	// f_de_merde(map, fdf);
	printf("key_hook : %d", mlx_key_hook(fdf->win, key_hook, fdf));
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
	mlx_loop(fdf->mlx);
	quit(fdf);
}
