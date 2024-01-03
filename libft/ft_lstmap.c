/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:17:23 by alafranc          #+#    #+#             */
/*   Updated: 2021/03/24 14:48:24 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tail;

	if (lst == NULL)
		return (NULL);
	if (!(ft_lstnew_prt(&new_list, 1, (size_t)f(lst->content))))
		return (NULL);
	tail = new_list;
	lst = lst->next;
	while (lst)
	{
		if (!(ft_lstnew_prt(&(tail->next), 1, (size_t)f(lst->content))))
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		tail = tail->next;
		lst = lst->next;
	}
	return (new_list);
}
