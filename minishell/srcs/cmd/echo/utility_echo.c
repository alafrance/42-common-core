/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:22:33 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 15:32:03 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_reverse_boolean(int boolean)
{
	if (boolean)
		return (0);
	return (1);
}

int	is_option(char *arg)
{
	int	i;

	if (!arg)
		return (0);
	i = 0;
	if (ft_is_backslash_before(arg, i, '-'))
	{
		if (arg[i])
			i++;
		if (!arg[i])
			return (0);
		while (arg[i] == 'n' && arg[i])
			i++;
		if (arg[i])
			return (0);
		else
			return (1);
	}
	return (0);
}
