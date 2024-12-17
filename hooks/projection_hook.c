/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 01:27:53 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 02:15:03 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	projection_hook(t_fdf *fdf)
{
	del_and_new_image(fdf);
	if (fdf->map_len->projection == 0)
		fdf->map_len->projection++;
	else if (fdf->map_len->projection == 1)
		fdf->map_len->projection++;
	else if (fdf->map_len->projection == 2)
		fdf->map_len->projection++;
	else
		fdf->map_len->projection = 0;
	render_map_plus(fdf);
}
