/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:39:30 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/28 16:39:12 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_and_exec(char *line, t_all *a)
{
	int	i;
	int	start;
	int	quote;

	i = 0;
	quote = 0;
	while (line[i])
	{
		start = i;
		ft_init_tree(a);
		while (line[i])
		{
			ft_is_quote(line[i], &quote);
			if (line[i] == ';' && !quote && !ft_is_bs_before(line, i))
				break ;
			i++;
		}
		a->tree = ft_binary_tree(line, start, i, a);
		if (line && !ft_check_error(a, line, &i))
			ft_exec_tree(a->tree, a);
		ft_reset(a);
		if (line[i])
			i++;
	}
}

void	ft_exec_tree(t_tree *node, t_all *a)
{
	if (node->type && node->type == op_pipe)
		ft_pipe(a);
	else if (node->type && node->type == redir)
	{
		ft_redir(node->exec->op, a);
		if (node->right != NULL)
			ft_exec_tree(node->right, a);
		if (node->left != NULL)
			ft_exec_tree(node->left, a);
		return ;
	}
	else if (node->type && node->type == command)
		ft_exec_cmd(node->exec->cmd, a);
	else if (node->type && node->type == file)
		ft_file(node, a);
	if (node->left != NULL)
		ft_exec_tree(node->left, a);
	if (node->right != NULL)
		ft_exec_tree(node->right, a);
}

void	ft_file(t_tree *node, t_all *a)
{
	int	fd;

	node->exec->file->file = parse_argument(a, node->exec->file->file)[0];
	if (a->redir->chevron)
		fd = open(node->exec->file->file, O_APPEND | O_CREAT | O_WRONLY, 0777);
	else if (!a->redir->input)
		fd = open(node->exec->file->file, O_TRUNC | O_CREAT | O_WRONLY, 0777);
	if (a->redir->input)
	{
		fd = open(node->exec->file->file, O_RDONLY, 0777);
		if (fd == -1)
			ft_error_input(node->exec->file->file, "No such file or directory", a);
		a->redir->fd = fd;
		a->redir->fd_backup = dup(0);
		dup2(fd, 0);
		close(fd);
	}
	else if (a->redir->count == 1)
	{
		a->redir->fd_backup = dup(a->redir->fd);
		dup2(fd, a->redir->fd);
		close(fd);
	}
}

void	ft_pipe(t_all *a)
{
	a->pipe->count += 1;
	a->pipe->is_pipe = 1;
}

void	ft_redir(t_operator *op, t_all *a)
{
	a->redir->fd = ft_atoi(op->op);
	if (ft_strlen(ft_strchr(op->op, '>')) == 2)
		a->redir->chevron = 1;
	else
		a->redir->chevron = 0;
	if (!ft_strcmp(op->op, "<"))
		a->redir->input = 1;
	else if (!a->redir->fd)
		a->redir->fd = 1;
	a->redir->count++;
}
