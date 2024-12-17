/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_scam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:31:20 by jbergos           #+#    #+#             */
/*   Updated: 2024/12/17 03:39:29 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	find_char(char c, char	*charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		++i;
	}
	return (0);
}

static size_t	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (find_char(str[i], charset))
			++i;
		if (!str[i])
			break ;
		++count;
		while (!find_char(str[i], charset) && str[i])
			++i;
	}
	return (count);
}

static void	free_table(char **pptr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(pptr[i]);
		++i;
	}
	free(pptr);
}

char	**ft_split_scam(char *s, char *charset)
{
	char	**pptr;
	size_t	i;
	size_t	j;
	size_t	end;

	pptr = malloc(sizeof(char *) * (count_word(s, charset) + 1));
	if (!pptr)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_word(s, charset))
	{
		while (s[i] && find_char(s[i], charset))
			++i;
		end = 0;
		while (s[i + end] != '\0' && !find_char(s[i + end], charset))
			++end;
		pptr[j++] = ft_substr(s + i, 0, end);
		if (!pptr[j - 1])
			return (free_table(pptr, j - 1), NULL);
		i += end;
	}
	pptr[j] = NULL;
	return (pptr);
}
