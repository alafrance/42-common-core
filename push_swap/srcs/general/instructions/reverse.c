/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:02:49 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/08 15:16:32 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_list(t_list **lst)
{
	t_list	*tmp;
	t_list	*begin;

	if (!*lst || !(*lst)->next)
		return ;
	begin = *lst;
	tmp = ft_lstlast(*lst);
	while ((*lst)->next->next)
		*lst = (*lst)->next;
	(*lst)->next = NULL;
	tmp->next = begin;
	*lst = tmp;
}

void	reverse_rotate_a(t_list **a, t_list **b, int is_print)
{
	(void)b;
	reverse_rotate_list(a);
	if (is_print)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_list **a, t_list **b, int is_print)
{
	(void)a;
	reverse_rotate_list(b);
	if (is_print)
		ft_printf("rrb\n");
}

void	reverse_rotate_a_b(t_list **a, t_list **b, int is_print)
{
	reverse_rotate_list(a);
	reverse_rotate_list(b);
	if (is_print)
		ft_printf("rrr\n");
}
