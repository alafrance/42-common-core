/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:13:22 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/20 10:35:50 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_sort_3(int count, t_list **lst)
{
	if (count == 2)
	{
		if ((*lst)->content > (*lst)->next->content)
			swap_a(lst, NULL, 1);
	}
	if (count == 3)
	{	
		if ((int)(*lst)->content > (int)ft_lstlast(*lst)->content
			&& (int)(*lst)->content > (int)(*lst)->next->content)
			rotate_a(lst, NULL, 1);
		if ((int)ft_lstlast(*lst)->content < (int)(*lst)->next->content)
			reverse_rotate_a(lst, NULL, 1);
		if ((int)(*lst)->content > (int)(*lst)->next->content)
			swap_a(lst, NULL, 1);
	}
}
