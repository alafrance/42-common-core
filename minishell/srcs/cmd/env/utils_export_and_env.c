/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export_and_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:58:33 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 15:49:40 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_only_equal(char *str)
{
	int	i;

	i = 0;
	(void)str;
	if (!str)
		return (1);
	while (str[i] == '=' && str[i])
		i++;
	if (!str[i])
		return (1);
	return (0);
}

int	ft_strchr_str(char *str, char *find)
{
	int	i;
	int	j;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		j = 0;
		while (find[j])
		{
			if (str[i] == find[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	push_variable_plus(char *str, t_all *a, t_status status)
{
	t_env	*new_elem;
	t_env	*env;

	new_elem = pick_key_and_content(str, &a->gc, status, '+');
	if (check_error_export(str, new_elem))
	{
		a->status = 1;
		return (0);
	}
	if (new_elem)
		env = ft_keyshr(a->env, new_elem->key);
	else
		env = NULL;
	if (new_elem && env)
		env->content = ft_strjoin(env->content, new_elem->content);
	return (1);
}

int	push_variable_equal(char *str, t_all *a, t_status status)
{
	t_env	*new_elem;
	t_env	*env;

	new_elem = pick_key_and_content(str, &a->gc, status, '=');
	if (check_error_export(str, new_elem))
	{
		a->status = 1;
		return (0);
	}
	if (new_elem)
		env = ft_keyshr(a->env, new_elem->key);
	else
		env = NULL;
	if (new_elem && env)
		ft_lst_remove_key(&a->env, env->key);
	if (new_elem)
	{
		ft_lstadd_back_env(&a->env, new_elem);
		ft_lstadd_front(&a->gc, ft_lstnew(new_elem));
	}
	return (1);
}

void	push_variable_whitout_export(t_command *cmd, t_all *a)
{
	int	i;

	i = -1;
	push_variable_equal(cmd->cmd, a, status_none);
	if (cmd->handle_arg)
		while (cmd->handle_arg[++i])
			push_variable_equal(cmd->handle_arg[i], a, status_none);
}
