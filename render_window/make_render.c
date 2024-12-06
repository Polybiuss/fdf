/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:42:40 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/06 02:48:02 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	render_map(t_map **map, t_fdf *fdf)
{
	t_map *tmp;

	if (!(*map))
		return ;
	tmp = (*map);
	while (tmp)
	{
		my_mlx_pixel_put(fdf, (tmp->x * 20) + tmp->xp, (tmp->y *20) + tmp->yp, 0x00FF0000);
		tmp = tmp->next;
	}
}

void	make_render(t_map **map)
{
	t_fdf *fdf;

	fdf = init_render();
	if (!fdf)
		return ;
	render_map(map, fdf);
	loop_render(fdf);
}