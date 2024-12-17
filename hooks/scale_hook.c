/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:34:15 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 02:17:23 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	scale_hook(t_fdf *fdf, int kc)
{
	if (kc == 119)
		fdf->map_len->scaley -= 1;
	if (kc == 115)
		fdf->map_len->scaley += 1;
	if (kc == 97)
		fdf->map_len->scalex -= 1;
	if (kc == 100)
		fdf->map_len->scalex += 1;
	del_and_new_image(fdf);
	render_map_plus(fdf);
}
