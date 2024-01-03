/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:46:05 by qurobert          #+#    #+#             */
/*   Updated: 2021/06/24 14:47:20 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_tree(t_all *a)
{
	a->tree = malloc_gc(&a->gc, sizeof(t_tree));
	a->tree->type = -1;
}

void	fill_env_(t_command *cmd, t_all *a)
{
	t_env	*env;

	env = ft_keyshr(a->env, "_");
	if (!env)
	{
		env = ft_lstnew_env("_", NULL, status_env);
		ft_lstadd_back_env(&a->env, env);
	}
	if (cmd->cmd && !ft_strcmp(cmd->cmd, "env"))
		env->content = ft_strdup_gc(&a->gc, "/usr/bin/env");
	else if (cmd->handle_arg && cmd->handle_arg[0])
		env->content = cmd->handle_arg[ft_strslen(cmd->handle_arg) - 1];
	else if (cmd->cmd)
		env->content = cmd->cmd;
}
