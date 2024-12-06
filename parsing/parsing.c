/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:49:35 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/06 01:16:12 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_map	*parse_map(char *str)
{
	int		fd;
	int		i;
	char	*line;
	t_map	*map;

	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	map = NULL;
	while (line)
	{
		create_map(&map, line, i);
		free(line);
		line = get_next_line(fd);
		++i;
	}
	if (line)
		free(line);
	get_next_line(-1);
	return (map);
}
