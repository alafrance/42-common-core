/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:36:00 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/09 13:28:20 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return (0);
	while (strs[i] != NULL)
		i++;
	return (i);
}

char	**ft_strsjoin_free(char **s1, char *s2)
{
	char	**strs;
	int		i;

	i = 0;
	strs = malloc(sizeof(char *) * (ft_strslen(s1) + 2));
	if (!(strs))
		return (NULL);
	if (s1)
	{	
		while (s1[i])
		{
			strs[i] = ft_strdup(s1[i]);
			i++;
		}
	}
	strs[i++] = ft_strdup(s2);
	strs[i] = NULL;
	free_all(s1, ft_strslen(s1));
	return (strs);
}

char	**ft_strsjoin(char **s1, char *s2)
{
	char	**strs;
	int		i;

	i = 0;
	strs = malloc(sizeof(char *) * (ft_strslen(s1) + 2));
	if (!(strs))
		return (NULL);
	if (s1)
	{	
		while (s1[i])
		{
			strs[i] = ft_strdup(s1[i]);
			i++;
		}
	}
	strs[i++] = ft_strdup(s2);
	strs[i] = NULL;
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
	strs = malloc(sizeof(char *) * (ft_strslen(s1) + 2));
	if (!(strs))
		return (NULL);
	while (s1[i])
	{
		strs[i] = ft_strdup(s1[i]);
		i++;
	}
	strs[i] = NULL;
	return (strs);
}

void	ft_strs_add_to_gc(char **strs, t_list **gc)
{
	int		i;

	i = -1;
	if (!strs)
		return ;
	ft_lstadd_front(gc, ft_lstnew(strs));
	while (strs[++i])
		ft_lstadd_front(gc, ft_lstnew(strs[i]));
}
