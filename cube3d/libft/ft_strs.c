/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:36:38 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/16 16:41:46 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strslen(char **strs)
{
	int i;

	i = 0;
	if (!strs)
		return (0);
	while (strs[i] != NULL)
		i++;
	return (i);
}

void	free_all(char **strs, int j)
{
	int i;

	i = 0;
	while (i != j)
		free(strs[i++]);
	if (strs)
		free(strs);
}

char	**ft_strsjoin(char **s1, char *s2)
{
	char	**strs;
	int		i;

	i = 0;
	if (!(strs = malloc(sizeof(char*) * (ft_strslen(s1) + 2))))
		return (NULL);
	if (s1)
		while (s1[i])
		{
			strs[i] = ft_strdup(s1[i]);
			i++;
		}
	strs[i++] = ft_strdup(s2);
	strs[i] = NULL;
	free_all(s1, ft_strslen(s1));
	return (strs);
}

char	**ft_strsdup(char **s1)
{
	char	**strs;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	if (!(strs = malloc(sizeof(char*) * (ft_strslen(s1) + 2))))
		return (NULL);
	while (s1[i])
	{
		strs[i] = ft_strdup(s1[i]);
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
