/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:42:47 by qurobert          #+#    #+#             */
/*   Updated: 2021/06/24 18:42:52 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_put_status(t_all *a, int status)
{
	a->status = status;
	ft_status_cmd(a, &a->status);
}

int	ft_print_error_msg(t_all *a, char *msg)
{
	ft_printf(2, "minichiale: syntax error near unexpected token `%s'\n", msg);
	ft_put_status(a, 258);
	return (1);
}

int	ft_check_empty_op(t_all *a, char *line)
{
	int	n;
	int	i;
	int	quote;

	i = 0;
	n = ft_strlen(line);
	quote = 0;
	if (line[0] == ';' && ((line[1] && line[1] != ';') || !line[1]))
		return (ft_print_error_msg(a, ";"));
	while (line[i])
	{
		ft_is_quote(line[i], &quote);
		if (line[i] == ';' && line[i + 1] && line[i + 1] == ';' && !quote)
			return (ft_print_error_msg(a, ";;"));
		i++;
	}
	return (0);
}

int	ft_check_redir(t_all *a, char *line)
{
	int	i;
	int	count;
	int	quote;

	i = -1;
	quote = 0;
	while (line[++i])
	{
		count = 0;
		ft_is_quote(line[i], &quote);
		if (ft_chevron(line, &i, quote, count))
			return (ft_print_error_msg(a, "<"));
		count = 0;
		while (line[i] == '>' && !quote)
		{
			count++;
			i++;
			if (count > 2)
				return (ft_print_error_msg(a, ">"));
		}
	}
	return (0);
}

int	ft_check_error(t_all *a, char *line, int *i)
{
	if (a->tree->type == op_pipe && (a->tree->left->type < command || \
	a->tree->right->type < command))
		return (ft_print_error_msg(a, "|"));
	if (a->tree->type == redir && a->tree->right->type != file)
		return (ft_print_error_msg(a, a->tree->exec->file->file));
	if (ft_check_redir(a, line) || ft_check_empty_op(a, line))
	{
		ft_skip(line, i);
		return (1);
	}
	return (0);
}
