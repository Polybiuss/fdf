/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:49:35 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 22:04:59 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	is_fdf_ext(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	if (i < 3)
		return (0);
	if (str[i - 1] == 'f' && str[i - 2]
		== 'd' && str[i - 3]
		== 'f' && str[i - 4]
		== '.')
		return (1);
	return (0);
}

t_map	*parse_map(char *str)
{
	int		fd;
	int		i;
	char	*line;
	t_map	*map;

	if (!is_fdf_ext(str))
		return (NULL);
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
