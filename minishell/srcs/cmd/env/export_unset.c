/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:34:43 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 15:43:11 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_msg_export(char *error)
{
	ft_printf(2, "minichiale: `%s': not a valid identifier\n", error);
}

int	check_error_export(char *str, t_env *new_elem)
{
	if (new_elem && new_elem->key && ft_isdigit(new_elem->key[0]))
		error_msg_export(str);
	else if (new_elem && !new_elem->key)
		error_msg_export(str);
	else if (new_elem && (new_elem->content
			&& is_only_equal(new_elem->content)))
		error_msg_export(str);
	else if (new_elem && (new_elem->key && is_only_equal(new_elem->key)))
		error_msg_export(str);
	else if (new_elem && ft_strchr_str(new_elem->key, "+\\.$.+}{-*#@!^~/%"))
		error_msg_export(str);
	else
		return (0);
	return (1);
}

t_env	*duplicate_env(t_env *env)
{
	t_env	*new_env;

	new_env = NULL;
	while (env)
	{
		ft_lstadd_back_env(&new_env,
			ft_lstnew_env(env->key, env->content, env->status));
		env = env->next;
	}
	return (new_env);
}

int	ft_export(t_all *a, char **args)
{
	int		i;
	t_env	*new_elem;
	char	*chr;

	i = -1;
	if (!args)
		return (ft_print_alphabetic_env(duplicate_env(a->env)));
	while (args[++i])
	{
		chr = ft_strchr(args[i], '+');
		if (chr && chr[1] == '=')
			push_variable_plus(args[i], a, status_env);
		else if (ft_strchr(args[i], '='))
			push_variable_equal(args[i], a, status_env);
		else
		{
			new_elem = ft_keyshr(a->env, args[i]);
			if (new_elem && new_elem->content)
				new_elem->status = status_env;
			else
				push_variable_equal(args[i], a, status_export);
		}
	}
	return (a->status);
}

int	ft_unset(t_all *a, char **args)
{
	int		i;
	t_env	*test;

	i = -1;
	if (!args)
		return (0);
	while (args[++i])
	{
		test = pick_key_and_content(args[i], &a->gc, status_none, '=');
		ft_lstadd_front(&a->gc, ft_lstnew(test));
		a->status = check_error_export(args[i], test);
		if (!a->status)
			ft_lst_remove_key(&a->env, args[i]);
	}
	return (a->status);
}
