/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:34:28 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 15:36:20 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_switch_link_begin(t_env **begin)
{
	t_env	**second;

	second = malloc(sizeof(t_env));
	*second = (*begin)->next;
	(*begin)->next = (*second)->next;
	(*second)->next = (*begin);
	(*begin) = *second;
}

void	ft_switch_link(t_env **previous, t_env **current, t_env **next)
{
	t_env	*tmp;

	tmp = (*previous);
	(*previous) = (*current);
	(*current) = (*next);
	(*next) = tmp;
}

void	ft_print_export(t_env *env)
{
	while (env)
	{
		if ((env->status == status_env || env->status == status_export)
			&& env->content)
			ft_printf(1, "declare -x %s=\"%s\"\n", env->key, env->content);
		else if ((env->status == status_env || env->status == status_export)
			&& !env->content)
			ft_printf(1, "declare -x %s\n", env->key);
		env = env->next;
	}
}

int	ft_print_alphabetic_env(t_env *env)
{
	t_env	*current;
	t_env	*previous;

	previous = NULL;
	current = env;
	while (current && current->next)
	{
		if (ft_strcmp(current->key, current->next->key) > 0)
		{
			if (previous)
				ft_switch_link(&previous->next, &current->next,
					&current->next->next);
			else
				ft_switch_link_begin(&env);
			previous = NULL;
			current = env;
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
	ft_print_export(env);
	return (0);
}
