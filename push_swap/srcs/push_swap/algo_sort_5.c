/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:13:27 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/14 07:23:16 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_minimun_b(t_list **a, t_list **b)
{
	int	min_i;
	int	lstsize;

	lstsize = ft_lstsize(*a);
	min_i = ft_minimum_number(*a);
	if (min_i >= 3)
		while (ft_minimum_number(*a))
			reverse_rotate_a(a, b, 1);
	else
		while (ft_minimum_number(*a))
			rotate_a(a, b, 1);
	push_b(a, b, 1);
}

void	algo_sort_5(int count, t_list **a, t_list **b)
{
	if (ft_lst_is_sort_simplify(*a))
		return ;
	push_minimun_b(a, b);
	if (count == 5)
		push_minimun_b(a, b);
	algo_sort_3(3, a);
	push_a(a, b, 1);
	if (count == 5)
		push_a(a, b, 1);
}
