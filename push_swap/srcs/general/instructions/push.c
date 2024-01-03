/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:59:35 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/08 15:16:47 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_list(t_list **add, t_list **remove)
{
	t_list	*tmp;

	if (!*remove)
		return ;
	tmp = *remove;
	*remove = (*remove)->next;
	tmp->next = *add;
	*add = tmp;
}

void	push_a(t_list **a, t_list **b, int is_print)
{
	push_list(a, b);
	if (is_print)
		ft_printf("pa\n");
}

void	push_b(t_list **a, t_list **b, int is_print)
{
	push_list(b, a);
	if (is_print)
		ft_printf("pb\n");
}
