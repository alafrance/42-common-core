/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:42:57 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 15:27:09 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_command_line(t_all *a)
{
	char	buf[256];
	int		cursor;
	char	*line;

	line = NULL;
	cursor = 0;
	a->input->line = &line;
	a->input->cursor = &cursor;
	ft_bzero(buf, 256);
	display_line(a);
	while (a->read && read(0, buf, 255))
	{
		if (ft_switch_keyboard(a, buf, &cursor, &line))
			break ;
		ft_bzero(buf, 256);
	}
}

void	ft_ctrl_l(t_all *a, char *line)
{
	t_command	*cmd;

	cmd = malloc_gc(&a->gc, sizeof(t_command));
	cmd->cmd = ft_strdup_gc(&a->gc, "clear");
	cmd->args = NULL;
	ft_exec_cmd(cmd, a);
	display_line(a);
	if (line)
		ft_printf(1, "%s", line);
}

int	ft_switch_keyboard(t_all *a, char buf[4], int *cursor, char **line)
{
	if (buf[0] == CTRL_D)
	{
		if (*cursor == 0)
			return (1);
	}
	else if (buf[0] == BACKSPACE || buf[0] == DEL)
		ft_backspace(&a->gc, cursor, line);
	else if (buf[0] == CTRL_U)
		ft_delete_line_to_cursor(&a->gc, cursor, line);
	else if (buf[0] == CTRL_L)
		ft_ctrl_l(a, *line);
	else if (buf[1] == '[')
		ft_arrow_key(a, buf[2], cursor, line);
	else if (buf[0] == '\n')
		ft_exec_termcap(a, cursor, line);
	else
		ft_print_buf_and_stock(a, line, buf, cursor);
	return (0);
}
