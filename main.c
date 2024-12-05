/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:21:50 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/05 01:58:36 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	// t_map *map;
	if (argc == 2)
	{
	parse_map(argv[1]);
	make_render();
	}
	return (0);
}
