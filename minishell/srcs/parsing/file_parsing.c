/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:16:13 by qurobert          #+#    #+#             */
/*   Updated: 2021/06/24 15:44:31 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr_gc(char const *s, unsigned int start, size_t len, t_all *a)
{
	char	*buf;
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		buf = malloc_gc(&a->gc, (sizeof(char) * 1));
		buf[0] = 0;
		return (buf);
	}
	while (size < len && s[start + size])
		size++;
	buf = malloc_gc(&a->gc, (sizeof(char) * (size + 1)));
	if (!buf)
		return (NULL);
	while (s[start] && i < len)
		buf[i++] = s[start++];
	buf[i] = '\0';
	return (buf);
}

int	ft_stop_index(char *line, int i)
{
	int	quote;

	quote = 0;
	while ((line[i] && line[i] != ' ' && line[i] != '>' && line[i] != '<' && \
	line[i] != ';' ) || (line[i] && quote))
	{
		ft_is_quote(line[i], &quote);
		i++;
	}
	return (i);
}

char	*ft_file_name(char *line, int *array, t_tree *node, t_all *a)
{
	int		start;
	int		end;
	int		ws;

	(void)node;
	(void)a;
	end = array[1];
	start = array[0];
	while (line[start] && (line[start] == '>' || line[start] == '<' || \
	line[start] == ' '))
		start++;
	ws = ft_stop_index(line, start);
	return (ft_substr(line, start, ws - start));
}

void	ft_malloc_file(char *line, int *array, t_tree *node, t_all *a)
{
	node->type = file;
	node->exec = malloc_gc(&a->gc, sizeof(t_type_union));
	node->exec->file = malloc_gc(&a->gc, sizeof(t_file));
	node->exec->file->file = ft_file_name(line, array, node, a);
	ft_lstadd_front(&a->gc, ft_lstnew(node->exec->file->file));
}
