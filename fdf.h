/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:02:36 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/12 01:24:15 by jbergos          ###   ########.fr       */
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
# define TX 1
# define TY 1
# define GAMMA -1.5
# define TETHA 0
# define ALPHA 0
// # define ROTATIONX 1
// # define ROTATIONY 1
// # define ROTATION 120

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
	double	gamma;
	double	tetha;
	double	alpha;
}	t_fdf;

typedef struct s_map
{
	int				x;
	int				y;
	int 			z;
	double				rx;
	double				ry;
	double				rz;
	double				posx;
	double				posy;
	double				xp;
	double				yp;
	char			*color;
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
	int	xe;
	int ye;
} t_line;

typedef struct s_map_len
{
	int width;
	int	heigth;
	int	mid_width;
	int	mid_heigth;
	t_map	*map;
} t_map_len;

t_fdf	*init_render(void);
void	quit(t_fdf *fdf);
int		key_hook(int keycode, t_fdf *fdf);
int		close_window(t_fdf *fdf);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void	loop_render(t_map_len *map, t_fdf *fdf);
void	make_render(t_map **map);
t_map	*parse_map(char *str);
t_map	*create_stack_map(int x, int y, int z);
void	map_add_back(t_map **head, t_map *back);
void	create_map(t_map **map, char *str, int y);
void	show_stack(t_map **map);
char	**ft_split_scam(char *s, char *charset);
void	make_render_plus(t_map_len *map);

#endif