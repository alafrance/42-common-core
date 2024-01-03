/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:31:34 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/08 15:44:35 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**all_instruction_on_tab(t_list **gc)
{
	char	**tab;

	tab = malloc_gc(gc, sizeof(char *) * 11);
	ft_strdup_gc(gc, &tab[0], "sa");
	ft_strdup_gc(gc, &tab[1], "sb");
	ft_strdup_gc(gc, &tab[2], "ss");
	ft_strdup_gc(gc, &tab[3], "pa");
	ft_strdup_gc(gc, &tab[4], "pb");
	ft_strdup_gc(gc, &tab[5], "ra");
	ft_strdup_gc(gc, &tab[6], "rb");
	ft_strdup_gc(gc, &tab[7], "rr");
	ft_strdup_gc(gc, &tab[8], "rra");
	ft_strdup_gc(gc, &tab[9], "rrb");
	ft_strdup_gc(gc, &tab[10], "rrr");
	return (tab);
}

int	is_instruction(char *str, t_list **gc)
{
	int		i;
	char	**tab;

	tab = all_instruction_on_tab(gc);
	i = -1;
	while (++i != 11)
		if (!ft_strcmp(str, tab[i]))
			return (1);
	return (0);
}

void	*init_array_instruction_function(t_list **gc)
{
	void	(**ft_instruction)(t_list **, t_list **, int);

	ft_instruction = malloc_gc(gc, sizeof(ft_instruction) * 11);
	ft_instruction[0] = &swap_a;
	ft_instruction[1] = &swap_b;
	ft_instruction[2] = &swap_a_b;
	ft_instruction[3] = &push_a;
	ft_instruction[4] = &push_b;
	ft_instruction[5] = &rotate_a;
	ft_instruction[6] = &rotate_b;
	ft_instruction[7] = &rotate_a_b;
	ft_instruction[8] = &reverse_rotate_a;
	ft_instruction[9] = &reverse_rotate_b;
	ft_instruction[10] = &reverse_rotate_a_b;
	return (ft_instruction);
}
