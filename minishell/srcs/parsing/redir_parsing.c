/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:16:33 by qurobert          #+#    #+#             */
/*   Updated: 2021/06/24 15:49:36 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_malloc_nb_redir(char *line, int *array, t_all *a)
{
	int		start;
	int		count;
	char	*str;

	count = 0;
	str = malloc_gc(&a->gc, sizeof(char) * (array[3] - array[2] + 2));
	start = array[2];
	while (line[start] && start <= array[3])
		str[count++] = line[start++];
	str[count] = '\0';
	return (str);
}

void	ft_malloc_redir(t_tree *node, t_all *a, int *array, char *line)
{
	int	start;
	int	end;
	int	op_pos;

	start = 0;
	end = 0;
	op_pos = array[2];
	node->exec = malloc_gc(&a->gc, sizeof(t_type_union));
	node->exec->op = malloc_gc(&a->gc, sizeof(t_operator));
	node->exec->op->op = ft_malloc_nb_redir(line, array, a);
}
