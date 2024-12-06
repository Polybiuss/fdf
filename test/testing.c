/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:18:09 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/06 02:38:58 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	show_stack(t_map **map)
{
	t_map	*tmp;

	if (!(*map))
	{
		ft_printf("c'est vide \n");
		return ;
	}
	tmp = (*map);
	while (tmp)
	{
		ft_printf("x : %d, y : %d, z : %d, xp : %d, yp : %d\n", tmp->x, tmp->y, tmp->z, tmp->xp, tmp->yp);
		tmp = tmp->next;
	}
}