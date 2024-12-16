/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:02:36 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/16 03:27:25 by jbergos          ###   ########.fr       */
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
# define C_DF 0x0045BB0E
# define C_B 0x000D5CDA
# define C_H 0x00DA150D


typedef struct s_map
{
	int				x;
	int				y;
	int 			z;
	int				color;
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
	int	xd;
	int	yd;
	int	y;
	int	z;
	int	xe;
	int ye;
	int	ze;
} t_line;

typedef struct s_map_len
{
	int			width;
	int			heigth;
	t_map		*map;
	double		gamma;
	double		alpha;
	double		theta;
	int			scalex;
	int			scaley;
	double		high;
	int			zoom;
	int			projection;
} t_map_len;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			endian;
	t_map_len	*map_len;
}	t_fdf;

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
void	make_render_plus(t_map_len *map);
void	rotate_z(t_map *map, double gamma);
void	rotate_map(t_map **map, void (f)(t_map*, double), double angle);
void	render_map_plus(t_map_len *map, t_fdf *fdf);
double	rotate_zx(double x, double y, double gamma);
double	rotate_zy(double x, double y, double gamma);
unsigned char	interpolate(unsigned char start, unsigned char end, float ratio);
#endif