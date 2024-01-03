/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:08:59 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 14:45:21 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*previous_current(t_list *lst, t_list *current,
		t_list *historic_current)
{
	if (!current || current == historic_current)
		return (ft_lstlast(lst));
	if (lst == current)
		return (lst);
	while (lst->next)
	{
		if (lst->next == current)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_change_line(t_list **gc, int *cursor, char **line, char *new_line)
{
	ft_delete_line(gc, cursor, line);
	*line = ft_strdup_gc(gc, new_line);
	*cursor = ft_strlen(*line);
	ft_printf(1, "%s", new_line);
}

char	**split_str_into_index(t_list **gc, char *str, int index)
{
	char	**str_split;

	str_split = malloc_gc(gc, sizeof(char *) * 2);
	str_split[0] = ft_substr(str, 0, index);
	str_split[1] = ft_substr(str, index, ft_strlen(str));
	if (!str_split[0] || !str_split[1])
		ft_error_msg("Malloc error", *gc);
	ft_lstadd_front(gc, ft_lstnew(str_split[0]));
	ft_lstadd_front(gc, ft_lstnew(str_split[1]));
	return (str_split);
}
