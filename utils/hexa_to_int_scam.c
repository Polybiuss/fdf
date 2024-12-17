/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_to_int_scam.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 03:37:03 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 03:38:41 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	is_comma(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (1);
		++i;
	}
	return (0);
}

int	hexa_to_int(char *z)
{
	int	res;
	int	value;
	int	i;

	i = 0;
	value = 0;
	if (z[0] == '0' && (z[1] == 'x' || z[1] == 'X'))
		i = 2;
	while (z[i])
	{
		if (ft_isdigit(z[i]))
			value = z[i] - '0';
		else if (z[i] >= 'A' && z[i] <= 'F')
			value = z[i] - 'A' + 10;
		else
			value = z[i] - 'a' + 10;
		res = res * 16 + value;
		++i;
	}
	return (res);
}

int	hexa_color(char *z)
{
	int	i;

	i = 0;
	while (z[i] != ',')
		++i;
	++i;
	return (hexa_to_int(z + i));
}
