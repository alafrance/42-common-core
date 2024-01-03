/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:49:38 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/21 15:38:37 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_number_on_the_top(t_list **a, t_list **b, int pos, int size)
{
	if (pos < (size + 1) / 2)
		while (pos-- > 0)
			rotate_a(a, b, 1);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			reverse_rotate_a(a, b, 1);
	}
	push_b(a, b, 1);
}

void	push_between_bounds(t_list **a, t_list **b,
							int bound_min, int bound_max)
{
	int		pos;
	int		size;
	t_list	*tmp;

	tmp = *a;
	size = ft_lstsize(*a);
	pos = 0;
	while (tmp)
	{
		if ((int)tmp->content >= bound_min && (int)tmp->content <= bound_max)
		{
			put_number_on_the_top(a, b, pos, size);
			tmp = *a;
			pos = -1;
		}
		else
			tmp = tmp->next;
		pos++;
	}
}

void	push_max_a(t_list **a, t_list **b)
{
	int	max_pos;
	int	lstsize;

	lstsize = ft_lstsize(*b);
	max_pos = ft_maximum_number(*b);
	if (max_pos > (lstsize + 1) / 2)
		while (max_pos++ != lstsize)
			reverse_rotate_b(a, b, 1);
	else
		while (max_pos--)
			rotate_b(a, b, 1);
	push_a(a, b, 1);
}

void	push_on_stack_b(t_list **a, t_list **b, int *tab, int size)
{
	int	number_bounds;
	int	bound_min_i;
	int	bound_max_i;
	int	i;

	i = 0;
	bound_max_i = 0;
	bound_min_i = 0;
	number_bounds = ft_sqrt_int(size) / 1.5;
	while (i != number_bounds)
	{
		bound_min_i = size / number_bounds * i;
		if (i != 0)
			bound_min_i++;
		if (i == number_bounds - 1)
			bound_max_i = size - 1;
		else
			bound_max_i = size / number_bounds * (i + 1);
		push_between_bounds(a, b, tab[bound_min_i], tab[bound_max_i]);
		i++;
	}
}

void	algo_sort(t_list **a, t_list **b, t_list **gc)
{
	int	*tab;
	int	size;

	size = ft_lstsize(*a);
	tab = create_tab(*a, gc, size);
	tab = sort_int_tab(tab, size);
	if (ft_lst_is_sort(*a, *b))
		return ;
	push_on_stack_b(a, b, tab, size);
	while (*b)
		push_max_a(a, b);
}
