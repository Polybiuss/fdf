/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:02:36 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/05 02:00:44 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
#include <fcntl.h>

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_fdf;

typedef struct s_map
{
	int				x;
	int				y;
	int 			z;
	struct s_map	*next;
} t_map;

t_fdf	*init_render(void);
void	quit(t_fdf *fdf);
int		key_hook(int keycode, t_fdf *fdf);
int		close_window(t_fdf *fdf);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void	loop_render(t_fdf *fdf);
void	make_render(void);
void	parse_map(char *str);

#endif