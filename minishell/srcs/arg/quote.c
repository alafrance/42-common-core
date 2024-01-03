/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:07:32 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 14:33:52 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_delete_empty_quote(char *str)
{
	int	i;
	int	count;

	count = 1;
	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i + 1])
	{
		if ((ft_is_backslash_before(str, i, '\'') && \
		ft_is_backslash_before(str, i + 1, '\''))
			|| (ft_is_backslash_before(str, i, '\"') && \
			ft_is_backslash_before(str, i + 1, '\"')))
			i += 2;
		else
		{
			count++;
			i++;
		}
	}
	return (count);
}

int	count_whitout_quote(char *args)
{
	int		count;
	int		i;
	char	quote;

	if (!args)
		return (0);
	count = 0;
	i = -1;
	while (args[++i])
	{
		if (quote == args[i])
			quote = 0;
		else if ((ft_is_backslash_before(args, i, '\'') && quote != '\"')
			|| (ft_is_backslash_before(args, i, '\"') && quote != '\''))
			quote = args[i];
		else
			count++;
	}
	return (count);
}

char	*delete_quote(t_list **gc, char *args)
{
	int		i;
	int		j;
	char	quote;
	char	*new_args;

	if (!args)
		return (NULL);
	i = -1;
	j = -1;
	quote = 0;
	new_args = malloc_gc(gc, sizeof(char) * (count_whitout_quote(args) + 1));
	while (args[++i])
	{
		if (quote == args[i])
			quote = 0;
		else if ((ft_is_backslash_before(args, i, '\'') && quote != '\"')
			|| (ft_is_backslash_before(args, i, '\"') && quote != '\''))
			quote = args[i];
		else
			new_args[++j] = args[i];
	}
	new_args[++j] = '\0';
	return (new_args);
}

char	*delete_empty_quote(t_list **gc, char *str)
{
	int		i;
	int		j;
	char	*new_str;

	if (!str)
		return (NULL);
	new_str = malloc_gc(gc, sizeof(char) * (count_delete_empty_quote(str) + 1));
	i = 0;
	j = 0;
	while (str[i] && str[i + 1])
	{
		if ((ft_is_backslash_before(str, i, '\'') && \
			ft_is_backslash_before(str, i + 1, '\'')) || \
			(ft_is_backslash_before(str, i, '\"') && \
			ft_is_backslash_before(str, i + 1, '\"')))
			i += 2;
		else
		{
			new_str[j++] = str[i];
			i++;
		}
	}
	new_str[j++] = str[i];
	new_str[j++] = '\0';
	return (new_str);
}
