/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:56:26 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 15:31:56 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_delete_option(char **args)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!args)
		return (0);
	while (args[i] && is_option(args[i]))
		i++;
	while (args[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	**delete_option(int *option, char **args)
{
	int		i;
	int		j;
	char	**new_args;

	new_args = malloc(sizeof(char *) * (count_delete_option(args) + 1));
	i = 0;
	j = -1;
	if (!args)
		return (0);
	while (args[i] && is_option(args[i]))
	{
		*option = 1;
		i++;
	}
	while (args[i])
		new_args[++j] = ft_strdup(args[i++]);
	new_args[++j] = NULL;
	return (new_args);
}

void	main_echo(char **args)
{
	int	i;

	i = -1;
	if (!args)
		return ;
	while (args[++i])
	{	
		ft_printf(1, "%s", args[i]);
		if (args[i + 1])
			ft_printf(1, " ");
	}
}

int	ft_echo(t_all *a, char **args)
{
	int		option;

	option = 0;
	args = delete_option(&option, args);
	ft_strs_add_to_gc(args, &a->gc);
	main_echo(args);
	if (!option)
		ft_printf(1, "\n");
	return (0);
}
