/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:45:11 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 15:33:13 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_all *a, char **args)
{
	t_env	*begin_env;

	(void)args;
	begin_env = a->env;
	while (a->env)
	{
		if (a->env->status == status_env)
			ft_printf(1, "%s=%s\n", a->env->key, a->env->content);
		a->env = a->env->next;
	}
	a->env = begin_env;
	return (0);
}
