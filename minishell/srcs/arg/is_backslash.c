/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_backslash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:01:25 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 14:21:30 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_backslash_before(char *str, int index, char c)
{
	if (index == 0 && str[index] == c)
		return (1);
	if (index != 0 && str[index] == c && str[index - 1] != '\\')
		return (1);
	return (0);
}

int	is_quote_or_d_quote(char *str, int index)
{
	if (index == 0 && (str[index] == '\'' || str[index] == '\"'))
		return (1);
	if (index != 0 && (str[index] == '\'' || str[index] == '\"') && \
	(str[index - 1] != '\\' || str[index - 1] != '\\'))
		return (1);
	return (0);
}
