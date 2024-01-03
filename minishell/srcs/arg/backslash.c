/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:01:18 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 14:19:06 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_add_backslash_quote(char *str)
{
	int	i;
	int	quote;
	int	count;

	i = -1;
	quote = 0;
	count = 0;
	while (str[++i])
	{
		if (ft_is_backslash_before(str, i, '\'') || \
		ft_is_backslash_before(str, i, '\"'))
			quote = ft_reverse_boolean(quote);
		else if (str[i] == '\\' && quote)
			count++;
		count++;
	}
	return (count);
}

char	*add_backslash_quote(t_list **gc, char *str)
{
	char	*new_str;
	int		i;
	int		j;
	int		quote;

	if (!str)
		return (NULL);
	new_str = malloc_gc(gc, sizeof(char) * count_add_backslash_quote(str));
	i = -1;
	j = -1;
	quote = 0;
	while (str[++i])
	{
		if (ft_is_backslash_before(str, i, '\'') || \
		ft_is_backslash_before(str, i, '\"'))
			quote = ft_reverse_boolean(quote);
		else if (str[i] == '\\' && quote)
			new_str[++j] = str[i];
		new_str[++j] = str[i];
	}
	return (str);
}

int	count_delete_backslash(char *str)
{
	int	i;
	int	count;
	int	quote;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	quote = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			quote = 1;
		if (str[i] == '\\' && !quote && str[i + 1])
		{
			count++;
			i += 2;
		}
		else
		{
			i++;
			count++;
		}
	}
	return (count);
}

char	*delete_backslash(t_list **gc, char *str)
{
	int		i;
	int		j;
	char	*new_str;
	int		quote;

	if (!str)
		return (str);
	i = 0;
	j = -1;
	quote = 0;
	new_str = malloc_gc(gc, sizeof(char) * (count_delete_backslash(str) + 1));
	while (str[i])
	{
		if (str[i] == '\'')
			quote = 1;
		if (str[i] == '\\' && !quote && str[i + 1])
		{
			new_str[++j] = str[i + 1];
			i += 2;
		}
		else
			new_str[++j] = str[i++];
	}
	new_str[++j] = '\0';
	return (new_str);
}
