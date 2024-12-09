/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:02:36 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/09 18:47:50 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# define SCALE 2
# define ANGLE 0.523599
# define WIDTH 1920
# define HEIGTH 1080
# define ZOOM 20
# define ROTATION 360

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
	int				rotatex;
	int				rotatey;
	int				xp;
	int				yp;
	int				posy;
	int				posx;
	struct s_map	*next;
} t_map;

typedef struct s_line
{
	int	dx;
	int dy;
	int	sx;
	int	sy;
	int	err;
	int	x;
	int	y;
} t_line;

t_fdf	*init_render(void);
void	quit(t_fdf *fdf);
int		key_hook(int keycode, t_fdf *fdf);
int		close_window(t_fdf *fdf);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void	loop_render(t_fdf *fdf);
void	make_render(t_map **map);
t_map	*parse_map(char *str);
t_map	*create_stack_map(int x, int y, int z);
void	map_add_back(t_map **head, t_map *back);
void	create_map(t_map **map, char *str, int y);
void	show_stack(t_map **map);
char	**ft_split_scam(char *s, char *charset);

#endif