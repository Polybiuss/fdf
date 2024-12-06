/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:21:50 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/06 01:15:31 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_map *map;
	
	if (argc == 2)
	{

	map = parse_map(argv[1]);
	show_stack(&map);
	make_render(&map);
	}
	return (0);
}
