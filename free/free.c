/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:12:40 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 00:24:59 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	close_window(t_fdf *fdf)
{
	quit(fdf);
	return (0);
}

void	free_lst(t_map *map)
{
	if (!map)
		return ;
	free_lst(map->next);
	free(map);
}

void	quit(t_fdf *fdf)
{
	if (fdf)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
		free_lst(fdf->map_len->map);
		free(fdf->map_len);
		free(fdf);
	}
	exit(0);
}

void	del_and_new_image(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGTH);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->ll, &fdf->endian);
}
