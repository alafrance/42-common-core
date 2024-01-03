/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:08:59 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 14:42:25 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*delete_char(int index_char, char *str, t_list **gc)
{
	int		i;
	int		j;
	char	*new_str;

	if (!str)
		return (NULL);
	new_str = malloc_gc(gc, sizeof(char) * ft_strlen(str));
	i = -1;
	j = -1;
	while (str[++i])
		if (i != index_char)
			new_str[++j] = str[i];
	new_str[++j] = '\0';
	return (new_str);
}

void	ft_delete_line_to_cursor(t_list **gc, int *cursor, char **line)
{
	if (!line || !(*line))
		return ;
	while (*cursor > 0)
		ft_backspace(gc, cursor, line);
}

void	ft_delete_line_from_cursor_into_line(t_list **gc, int *cursor,
			char **line)
{
	int	cursor_remember;

	if (!line || !(*line))
		return ;
	cursor_remember = *cursor;
	while ((size_t)(*cursor) < ft_strlen(*line))
		ft_right_arrow(cursor, ft_strlen(*line));
	while (*cursor > cursor_remember)
		ft_backspace(gc, cursor, line);
}

void	ft_delete_line(t_list **gc, int *cursor, char **line)
{
	if (!line || !(*line))
		return ;
	while ((size_t)(*cursor) < ft_strlen(*line))
		ft_right_arrow(cursor, ft_strlen(*line));
	while (*cursor > 0)
		ft_backspace(gc, cursor, line);
}

void	ft_backspace(t_list **gc, int *cursor, char **line)
{
	if (*cursor == 0 || !line || !(*line))
		return ;
	(*cursor)--;
	tputs(tgetstr("le", NULL), 1, ft_putchar_int);
	tputs(tgetstr("dc", NULL), 1, ft_putchar_int);
	*line = delete_char(*cursor, *line, gc);
}
