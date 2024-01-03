/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:18:32 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/08 15:39:05 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_all(char **strs, int index)
{
	int	i;

	i = 0;
	if (index < 0)
		return ;
	while (i != index)
		free(strs[i++]);
	free(strs);
}

static char	*malloc_a_case(const char *str, char c, char **strs, int index)
{
	int		i;
	char	*buf;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	buf = malloc(sizeof(char) * (i + 1));
	if (!buf)
	{
		free_all(strs, index);
		return (NULL);
	}
	i = 0;
	while (str[i] != c && str[i])
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

static int	malloc_all(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;

	i = 0;
	strs = malloc(sizeof(char *) * (malloc_all(s, c) + 1));
	if (!s || !strs)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			strs[i] = malloc_a_case(s, c, strs, i);
			if (!(strs[i]))
				return (NULL);
			while (*s != c && *s)
				s++;
			i++;
		}
	}
	strs[i] = NULL;
	return (strs);
}
