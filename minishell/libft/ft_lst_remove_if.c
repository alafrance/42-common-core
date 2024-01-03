/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:43:59 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/08 14:16:32 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove_if(t_list **lst, t_list *remove)
{
	t_list	*begin;

	begin = *lst;
	if (remove == *lst)
	{
		*lst = (*lst)->next;
		return ;
	}
	while (*lst && (*lst)->next)
	{
		if ((*lst)->next == remove)
		{
			(*lst)->next = (*lst)->next->next;
			*lst = begin;
			return ;
		}
		*lst = (*lst)->next;
	}
	*lst = begin;
}
