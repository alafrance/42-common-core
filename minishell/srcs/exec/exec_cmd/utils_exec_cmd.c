/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:53:37 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 14:54:11 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_our_cmd(t_command *cmd, char **cmd_done)
{
	int		i;

	i = -1;
	while (cmd_done[++i])
		if (cmd->cmd && !ft_strcmp(cmd->cmd, cmd_done[i]))
			return (i);
	return (-1);
}

int	ft_exec_cmd_error(t_command *cmd, t_all *a)
{
	if (cmd->error)
	{
		if (cmd->error == 127)
			ft_cmd_not_found(a, cmd->cmd);
		if (cmd->error == 126)
			ft_error_is_a_directory(a, cmd->cmd);
		return (1);
	}
	return (0);
}

void	ft_dup_for_pipe(t_all *a)
{
	if (a->pipe->is_pipe)
	{
		dup2(a->pipe->backup_tmp, 0);
		if (a->pipe->count != 0)
			dup2(a->pipe->fd[1], 1);
		close(a->pipe->fd[0]);
	}
}
