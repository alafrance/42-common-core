/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:10:22 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 14:56:53 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec_cmd_fork(t_command *cmd, t_all *a,
			int (**ft_cmd)(t_all *a, char **args))
{
	int		status;
	pid_t	pid;

	if (a->pipe->is_pipe)
		if (pipe(a->pipe->fd) == -1)
			ft_error_msg("PIPE INIT", a->gc);
	pid = fork();
	if (pid == 0)
	{
		ft_dup_for_pipe(a);
		if (cmd->our_cmd != -1)
			ft_cmd[cmd->our_cmd](a, cmd->handle_arg);
		else
			execve(cmd->cmd, cmd->handle_arg,
				convert_env_to_strs(&a->gc, a->env));
		exit(0);
	}
	wait(&status);
	a->pipe->count -= 1;
	close(a->pipe->fd[1]);
	ft_lst_add_fd(a, a->pipe->fd[0]);
	a->pipe->backup_tmp = a->pipe->fd[0];
	a->status = WEXITSTATUS(status);
}

void	ft_status_cmd(t_all *a, int *status_cmd)
{
	t_env	*env;

	env = ft_keyshr(a->env, "?");
	if (!env)
		return ;
	env->content = ft_itoa(*status_cmd);
	ft_lstadd_front(&a->gc, ft_lstnew(env->content));
	*status_cmd = 0;
}

void	ft_exec_cmd_main(t_command *cmd, t_all *a)
{
	int		(**ft_cmd)(t_all *a, char **args);

	ft_cmd = init_array_instruction_function(&a->gc);
	if (ft_exec_cmd_error(cmd, a))
		return ;
	if (cmd->our_cmd != -1 && !a->pipe->is_pipe)
		ft_cmd[cmd->our_cmd](a, cmd->handle_arg);
	else
		ft_exec_cmd_fork(cmd, a, ft_cmd);
}

void	ft_exec_cmd(t_command *cmd, t_all *a)
{
	if (!cmd || !cmd->cmd)
		return ;
	a->in_cmd = 1;
	cmd->cmd = parse_argument(a, cmd->cmd)[0];
	cmd->handle_arg = parse_argument(a, cmd->args);
	cmd->error = 0;
	fill_env_(cmd, a);
	if (cmd->cmd && ft_strchr(cmd->cmd, '='))
		push_variable_whitout_export(cmd, a);
	else
	{
		cmd->our_cmd = ft_is_our_cmd(cmd, list_cmd_done(&a->gc));
		if (cmd->our_cmd == -1)
			fill_cmd_with_path(cmd, a);
		ft_exec_cmd_main(cmd, a);
		a->in_cmd = 0;
	}
	ft_status_cmd(a, &a->status);
	if (a->redir->fd != -1)
		reset_redir(a);
}
