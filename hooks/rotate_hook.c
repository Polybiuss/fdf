/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 01:08:17 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 02:17:06 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rotate_hook(t_fdf *fdf, int kc)
{
	if (kc == 65361)
		fdf->map_len->theta -= 0.1;
	if (kc == 65363)
		fdf->map_len->theta += 0.1;
	if (kc == 65364)
		fdf->map_len->alpha -= 0.1;
	if (kc == 65362)
		fdf->map_len->alpha += 0.1;
	if (kc == 44)
		fdf->map_len->gamma += 0.1;
	if (kc == 46)
		fdf->map_len->gamma -= 0.1;
	del_and_new_image(fdf);
	render_map_plus(fdf);
}
