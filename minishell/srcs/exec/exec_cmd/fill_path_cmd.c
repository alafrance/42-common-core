/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_path_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:10:22 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 14:48:11 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_a_directory(char *cmd_path)
{
	struct stat	buf;
	int			ret;

	ret = lstat(cmd_path, &buf);
	if (!ret && S_ISDIR(buf.st_mode))
		return (1);
	return (0);
}

int	ft_test_with_path(t_command *cmd, t_all *a)
{
	struct stat	buf;
	char		**path_cmd;
	int			i;
	t_env		*path;

	i = -1;
	path = ft_keyshr(a->env, "PATH");
	if (!path)
		return (-1);
	path_cmd = ft_split(path->content, ':');
	while (path_cmd[++i])
	{
		if ((path_cmd[i])[ft_strlen(path_cmd[i]) - 1] != '/')
			path_cmd[i] = ft_strjoin_free(path_cmd[i], "/");
		path_cmd[i] = ft_strjoin_free(path_cmd[i], cmd->cmd);
		if (lstat(path_cmd[i], &buf) == 0)
		{
			cmd->cmd = path_cmd[i];
			ft_strs_add_to_gc(path_cmd, &a->gc);
			return (1);
		}
	}
	cmd->error = 127;
	ft_strs_add_to_gc(path_cmd, &a->gc);
	return (0);
}

void	ft_test_with_path_directly(t_command *cmd, t_all *a)
{
	struct stat	buf;

	if (ft_is_a_directory(cmd->cmd))
	{
		a->status = 126;
		return ;
	}
	if (lstat(cmd->cmd, &buf) == 0)
		return ;
	a->status = 127;
}

void	fill_cmd_with_path(t_command *cmd, t_all *a)
{
	cmd->handle_arg = ft_strsjoin_begin(cmd->handle_arg, a->name_prg);
	ft_strs_add_to_gc(cmd->handle_arg, &a->gc);
	if (cmd->cmd && ft_strchr(cmd->cmd, '/'))
		ft_test_with_path_directly(cmd, a);
	else
		ft_test_with_path(cmd, a);
}
