/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin_before.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:00:26 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/15 14:42:15 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsjoin_begin(char **strs, char *str)
{
	int		i;
	int		j;
	char	**new_strs;

	i = -1;
	j = 0;
	new_strs = malloc(sizeof(char *) * (ft_strslen(strs) + 2));
	if (!new_strs)
		return (NULL);
	new_strs[0] = ft_strdup(str);
	if (strs)
		while (strs[++i])
			new_strs[++j] = ft_strdup(strs[i]);
	new_strs[++j] = NULL;
	return (new_strs);
}
