/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2021/04/08 15:44:30 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pick_instruction(t_list **instruction, t_list **gc)
{
	char	*line;
	t_list	*new;
	t_list	*begin;

	line = NULL;
	new = NULL;
	begin = NULL;
	while (get_next_line(0, &line) && line[0])
	{
		if (!line || !is_instruction(line, gc))
		{
			if (line)
				free(line);
			ft_error(*gc);
		}
		ft_lstadd_back(instruction, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	if (line)
		free(line);
}

void	do_instruction(t_list *instruction, t_list **gc, t_list **a, t_list **b)
{
	char	**tab;
	void	(**ft_instruction)(t_list **, t_list **, int);
	int		i;

	tab = all_instruction_on_tab(gc);
	ft_instruction = init_array_instruction_function(gc);
	while (instruction)
	{
		i = -1;
		while (++i != 11)
		{
			if (!ft_strcmp(instruction->content, tab[i]))
			{
				ft_instruction[i](a, b, 0);
				break ;
			}
		}
		instruction = instruction->next;
	}
}

void	checker(t_list **a, t_list **b, t_list **gc)
{
	t_list	*instruction;

	instruction = NULL;
	pick_instruction(&instruction, gc);
	do_instruction(instruction, gc, a, b);
	if (ft_lst_is_sort(*a, *b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
