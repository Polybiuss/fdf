/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:23:21 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/16 03:59:07 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "../mlx_linux/mlx_int.h"

int	key_hook(int keycode, t_fdf *fdf)
{
	printf("Key: %d\n", keycode);
	if (keycode == 65307)
		quit(fdf);
	if(keycode == 65361)
		{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->theta -= 0.1; 
		render_map_plus(fdf->map_len, fdf);
		}
	if (keycode == 65363)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->theta += 0.1;
		render_map_plus(fdf->map_len, fdf);
	}
	if (keycode == 65364)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->alpha -= 0.1;
		render_map_plus(fdf->map_len, fdf);
	}
	if (keycode == 65362)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->alpha += 0.1;
		render_map_plus(fdf->map_len, fdf);
	}
	if (keycode == 65293)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->alpha = 0.0;
		fdf->map_len->theta = 0.0;
		fdf->map_len->gamma = 0.0;
		fdf->map_len->scalex = 0;
		fdf->map_len->scaley = 0;
		fdf->map_len->high = 1;
		fdf->map_len->zoom = 1;
		render_map_plus(fdf->map_len, fdf);
	}
	if (keycode == 44)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->gamma += 0.1;
		render_map_plus(fdf->map_len, fdf);
	}
	if (keycode == 46)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->gamma -= 0.1;
		render_map_plus(fdf->map_len, fdf);
	}
	if (keycode == 119)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->scaley -= 1;
		render_map_plus(fdf->map_len, fdf);
	}
	if (keycode == 115)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->scaley += 1;
		render_map_plus(fdf->map_len, fdf); 
	}
	if (keycode == 97)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->scalex -= 1;
		render_map_plus(fdf->map_len, fdf); 
	}
	if (keycode == 100)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->scalex += 1;
		render_map_plus(fdf->map_len, fdf); 
	}
	if (keycode == 45)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->high -= 0.01;
		render_map_plus(fdf->map_len, fdf); 
	}
	if (keycode == 61)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->high += 0.01;
		render_map_plus(fdf->map_len, fdf); 
	}
	if (keycode == 57)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->zoom--;
		render_map_plus(fdf->map_len, fdf); 
	}
	if (keycode == 48)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->zoom++;
		render_map_plus(fdf->map_len, fdf);
	}
	if (keycode == 65506)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		if (fdf->map_len->projection == 0)
			fdf->map_len->projection++;
		else if (fdf->map_len->projection == 1)
			fdf->map_len->projection++;
		else
			fdf->map_len->projection = 0;
		render_map_plus(fdf->map_len, fdf);
	}
	return (0);
}

int	mouse_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 1)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->zoom++;
		render_map_plus(fdf->map_len, fdf);
	}
	if (keycode == 3)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
		fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
		fdf->map_len->zoom--;
		render_map_plus(fdf->map_len, fdf);
	}
	if (keycode == 1)
		ft_printf("cela marche tkt\n");
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

void	loop_render(t_fdf *fdf)
{
	// mlx_mouse_hook(fdf->win, mouse_hook, fdf);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
	mlx_loop(fdf->mlx);
	quit(fdf);
}
