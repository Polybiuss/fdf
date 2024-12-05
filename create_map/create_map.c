/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:22:00 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/05 02:30:34 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_map	*create_map(int x, int y)
{
	t_map *new;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->next = NULL;
	return (new);
}

void	map_add_back(t_map **head, t_map *back)
{
	t_map	*tmp;

	if ((*head))
		*head = back;
	tmp = (*head);
	while (tmp)
	{
		if (!tmp->next)
		 break;
		 tmp = tmp->next;
	}
	tmp->next = back;
}