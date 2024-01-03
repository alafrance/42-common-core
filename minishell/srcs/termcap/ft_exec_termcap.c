/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_termcap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:53:58 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 14:43:51 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	stock_to_historic(t_all *a, char *line)
{
	t_list	*new_historic;

	if (line && line[0] != '\0')
	{
		new_historic = ft_lstnew(line);
		ft_lstadd_front(&a->gc, ft_lstnew(new_historic));
		ft_lstadd_back(&a->input->historic, new_historic);
	}
}

void	ft_exec_termcap(t_all *a, int *cursor, char **line)
{
	ft_printf(1, "\n");
	stock_to_historic(a, *line);
	apply_termios(a->input->saved);
	if (*line)
		ft_parse_and_exec(*line, a);
	if (a->read)
		display_line(a);
	reset_variable_termcap(a, cursor, line);
}

void	reset_variable_termcap(t_all *a, int *cursor, char **line)
{
	*cursor = 0;
	init_terms(a);
	*line = NULL;
	a->input->historic_current->content = "";
	a->input->ptr_historic = NULL;
}
