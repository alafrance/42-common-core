/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buf_and_stock.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:08:36 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 14:44:45 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_buf(char *str, int *cursor)
{
	int	size_print;
	int	i;

	if (!str)
		return (0);
	i = -1;
	size_print = 0;
	while (str[++i])
		if (ft_isprint(str[i]))
			size_print += ft_printf(1, "%c", str[i]);
	if (size_print == 0)
		return (0);
	(*cursor) += size_print;
	return (1);
}

void	add_string_into_line(t_list **gc, char **line, char *buf, int *cursor)
{
	char	**str_split;
	int		cursor_remember;
	int		size_print;
	int		i;

	i = -1;
	while (buf[++i])
		if (!ft_isprint(buf[i]))
			return ;
	str_split = split_str_into_index(gc, *line, *cursor);
	ft_delete_line_from_cursor_into_line(gc, cursor, line);
	*line = ft_strjoin(str_split[0], ft_strdup_gc(gc, buf));
	*line = ft_strjoin_free(*line, str_split[1]);
	ft_lstadd_front(gc, ft_lstnew(*line));
	cursor_remember = *cursor + 1;
	size_print = ft_printf(1, "%s", buf);
	size_print = ft_printf(1, "%s", str_split[1]);
	*cursor += size_print + 1;
	while (*cursor > cursor_remember)
		ft_left_arrow(cursor);
	*cursor = ft_strlen(str_split[0]) + ft_strlen(buf);
}

void	ft_print_buf_and_stock(t_all *a, char **line, char *buf, int *cursor)
{
	if (ft_strlen(*line) != (size_t)(*cursor))
	{
		add_string_into_line(&a->gc, line, buf, cursor);
		return ;
	}
	if (ft_print_buf(buf, cursor))
	{	
		if (!line || !(*line))
			*line = ft_strdup_gc(&a->gc, buf);
		else
		{
			*line = ft_strjoin(*line, buf);
			ft_lstadd_front(&a->gc, ft_lstnew(*line));
		}
		a->input->historic_current = ft_lstnew(*line);
		ft_lstadd_front(&a->gc, ft_lstnew(a->input->historic_current));
	}
}
