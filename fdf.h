/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:02:36 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 03:35:59 by jbergos          ###   ########.fr       */
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
	int				z;
	int				color;
	struct s_map	*next;
}	t_map;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	x;
	int	xd;
	int	yd;
	int	y;
	int	z;
	int	xe;
	int	ye;
	int	ze;
}	t_line;

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
}	t_map_len;

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

t_fdf			*init_render(void);
void			quit(t_fdf *fdf);
int				key_hook(int keycode, t_fdf *fdf);
int				close_window(t_fdf *fdf);
void			my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void			loop_render(t_fdf *fdf);
t_map			*parse_map(char *str);
t_map			*create_stack_map(int x, int y, int z);
void			map_add_back(t_map **head, t_map *back);
void			create_map(t_map **map, char *str, int y);
void			show_stack(t_map **map);
char			**ft_split_scam(char *s, char *charset);
void			make_render_plus(t_map_len *map);
void			render_map_plus(t_fdf *fdf);
unsigned char	interpolate(unsigned char s, unsigned char e, float ratio);
int				color_by_u_char(int heigth, int dft, int border);
int				color_for_heigth(int heigth);
int				ratio_gradient_color_x(int s_color, int e_color, t_line line);
int				ratio_gradient_color_y(int s_color, int e_color, t_line line);
int				gradient_color(t_map *start, t_map *end, t_line line);
int				close_window(t_fdf *fdf);
void			free_lst(t_map *map);
void			quit(t_fdf *fdf);
void			del_and_new_image(t_fdf *fdf);
void			scale_hook(t_fdf *fdf, int keycode);
void			rotate_hook(t_fdf *fdf, int kc);
void			reset_hook(t_fdf *fdf);
void			zoom_n_high_hook(t_fdf *fdf, int kc);
void			projection_hook(t_fdf *fdf);
double			iso_project_y(double x, double y, double z, int zoom);
double			cabinet_project_y(double y, double z, int zoom);
double			parrallel_projection_y(double y, double z, int zoom);
double			wich_projection_y(t_map_len *map, double x, double y, double z);
double			iso_project_x(double x, double y, int zoom);
double			cabinet_project_x(double x, double z, int zoom);
double			parallel_projection_x(double x, int zoom);
double			wich_projection_x(t_map_len *map, double x, double y, double z);
void			rotate_s(t_map *map, t_map_len *map_len, t_line *line);
void			rotate_e(t_map *map, t_map_len *map_len, t_line *line);
t_line			create_line_plus(t_map *start, t_map *end, t_map_len *map);
int				is_comma(char *str);
int				hexa_color(char *z);
int				hexa_to_int(char *z);

#endif