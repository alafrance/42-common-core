/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:27:49 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/08 13:02:26 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **a, t_list **b, t_list **gc)
{
	int	count;

	count = ft_lstsize(*a);
	if (count <= 3)
		algo_sort_3(count, a);
	else if (count <= 5)
		algo_sort_5(count, a, b);
	else
		algo_sort(a, b, gc);
}
