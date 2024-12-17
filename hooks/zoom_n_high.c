/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_n_high.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 01:24:05 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 02:16:03 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom_n_high_hook(t_fdf *fdf, int kc)
{
	if (kc == 45)
		fdf->map_len->high -= 0.02;
	if (kc == 61)
		fdf->map_len->high += 0.02;
	if (kc == 57)
		fdf->map_len->zoom--;
	if (kc == 48)
		fdf->map_len->zoom++;
	del_and_new_image(fdf);
	render_map_plus(fdf);
}
