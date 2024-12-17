/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 01:21:51 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 02:16:28 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	reset_hook(t_fdf *fdf)
{
	del_and_new_image(fdf);
	fdf->map_len->alpha = 0.0;
	fdf->map_len->theta = 0.0;
	fdf->map_len->gamma = 0.0;
	fdf->map_len->scalex = 0;
	fdf->map_len->scaley = 0;
	fdf->map_len->high = 1;
	fdf->map_len->zoom = 1;
	render_map_plus(fdf);
}
