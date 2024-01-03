/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:14:32 by qurobert          #+#    #+#             */
/*   Updated: 2021/06/24 15:45:53 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_tree(t_tree *node, int count)
{
	if (node->type && node->type == op_pipe)
		ft_printf(1, BLU "node %d : "RESET"pipe\n", count);
	else if (node->type && node->type == redir)
		ft_printf(1, BLU "node %d : "RESET"redir : %s\n", \
		count, node->exec->op->op);
	else if (node->type && node->type == command)
		ft_printf(1, BLU "node %d : "RESET"cmd = %s\t arg = %s\n", \
		count, node->exec->cmd->cmd, node->exec->cmd->args);
	else if (node->type && node->type == file)
		ft_printf(1, BLU "node %d : "RESET"file name : %s\n", \
		count, node->exec->file->file);
	ft_printf(1, "\n");
	if (node->left != NULL)
		ft_print_tree(node->left, count + 1);
	if (node->right != NULL)
		ft_print_tree(node->right, count + 1);
}

void	ft_print_start_to_end(char *line, int start, int end)
{
	int	i;

	i = 0;
	dprintf(1, "start = %d\tend = %d\n", start, end);
	while (line[start] && start < end)
	{
		write(1, &line[start], 1);
		start++;
	}
	write(1, "\n", 1);
}
