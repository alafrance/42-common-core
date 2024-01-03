/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:59:58 by qurobert          #+#    #+#             */
/*   Updated: 2021/06/24 16:04:50 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_file(char *line, int start)
{
	if (start > 0)
	{
		if (start > 0 && line[start] != '>' && line[start] != '<')
			start--;
		while (start > 0 && line[start] == ' ')
			start--;
		if (line[start] && (line[start] == '>' || line[start] == '<') && \
		!ft_is_bs_before(line, start))
			return (1);
	}
	return (0);
}

int	*ft_array_op(char *line, int end, t_all *a)
{
	int	count;
	int	pos;
	int	*op_pos;
	int	plus;

	count = 0;
	pos = 0;
	plus = 0;
	op_pos = malloc_gc(&a->gc, sizeof(int) * 2);
	if (end > -1 && line[end] && (line[end] == '<' || \
	line[end] == '>' || line[end] == '|') && !ft_is_bs_before(line, end))
	{
		op_pos[1] = end;
		plus = ft_check_name(&pos, &end, &count, line);
		if (count > 1)
			op_pos[0] = pos + plus;
		else
			op_pos[0] = end + plus;
	}
	else
	{
		op_pos[0] = -1;
		op_pos[1] = -1;
	}
	return (op_pos);
}

void	ft_priority(char *line, int start, int end, t_tree *node)
{
	int	quote;
	int	beg;

	quote = 0;
	node->type = -1;
	beg = start;
	while (line[start] && start < end)
	{
		ft_is_quote(line[start], &quote);
		if (line[start] == '|' && !quote && !ft_is_bs_before(line, start))
			node->type = op_pipe;
		else if ((line[start] == '>' || line[start] == '<') && \
		node->type < redir && !quote && !ft_is_bs_before(line, start))
			node->type = redir;
		else if (node->type < other && !quote && !ft_is_bs_before(line, start))
			node->type = other;
		start++;
	}
	if (ft_is_file(line, beg) && node->type == other)
		node->type = file;
}

int	*ft_op_pos(char *line, int end, t_tree *node, t_all *a)
{
	int	quote;

	quote = 0;
	while (end > -1 && line[end] && end >= node->start)
	{
		ft_is_quote(line[end], &quote);
		if (line[end] == '|' && node->type == op_pipe && \
		!ft_is_bs_before(line, end) && !quote)
			return (ft_array_op(line, end, a));
		if ((line[end] == '>' || line[end] == '<') && \
		node->type == redir && !ft_is_bs_before(line, end) && !quote)
			return (ft_array_op(line, end, a));
		end--;
	}
	return (ft_array_op(line, end, a));
}
