/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:10:19 by qurobert          #+#    #+#             */
/*   Updated: 2021/06/24 15:44:48 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_cmd_after(int **array, t_tree *node, t_all *a)
{
	int	s;
	int	beg;
	int	end;

	(void)a;
	s = node->start;
	while (node->line[s] && ft_delimiter(node->line[s], " ><123456789"))
		s++;
	while (node->line[s] && !ft_delimiter(node->line[s], " ><|;"))
		s++;
	while (node->line[s] && node->line[s] == ' ')
		s++;
	beg = s;
	while (node->line[s] && !ft_delimiter(node->line[s], "><|;"))
		s++;
	end = s;
	if (end - beg > 0)
	{
		(*array)[0] = beg;
		(*array)[1] = end;
		return (1);
	}
	return (0);
}

void	ft_put_in_array(int **array, int *op_pos, t_tree *node, t_all *a)
{
	(*array) = malloc_gc(&a->gc, sizeof(int) * 4);
	if (node->type == -1)
	{
		if (ft_check_cmd_after(array, node, a))
			node->type = 0;
	}
	else
	{
		(*array)[0] = node->start;
		(*array)[1] = node->end;
	}
	(*array)[3] = op_pos[1];
	(*array)[2] = op_pos[0];
}

void	ft_parsing(char *line, int *array, t_tree *node, t_all *a)
{
	int	start;
	int	end;

	start = array[0];
	end = array[1];
	if (node->type == file)
		ft_malloc_file(line, array, node, a);
	else if (node->type == op_pipe)
		node->exec = NULL;
	else if (node->type == redir)
		ft_malloc_redir(node, a, array, line);
	else if (node->type == other)
		ft_malloc_command(line, array, node, a);
}

t_tree	*ft_binary_tree(char *line, int start, int end, t_all *a)
{
	t_tree	*node;
	int		*op_pos;
	int		*array;

	node = malloc_gc(&a->gc, sizeof(t_tree));
	ft_priority(line, start, end, node);
	node->start = start;
	node->end = end;
	node->line = line;
	op_pos = ft_op_pos(line, end - 1, node, a);
	ft_put_in_array(&array, op_pos, node, a);
	ft_parsing(line, array, node, a);
	if (node->type == op_pipe || node->type == redir)
	{
		node->left = ft_binary_tree(line, start, op_pos[0] - 1, a);
		node->right = ft_binary_tree(line, op_pos[1] + 1, end, a);
	}
	else
	{
		node->left = NULL;
		node->right = NULL;
	}
	return (node);
}
