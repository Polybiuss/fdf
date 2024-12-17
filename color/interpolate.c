/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:15:25 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/16 23:16:57 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

unsigned char	interpolate(unsigned char start, unsigned char end, float ratio)
{
	return ((unsigned char)(start + ratio * (end - start)));
}
