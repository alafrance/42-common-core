/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_is_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:06:20 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/08 15:18:55 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	ft_lst_is_sort(t_list *a, t_list *b)
{
	int	big;

	if (b)
		return (0);
	if (!a)
		return (1);
	big = (int)a->content;
	while (a)
	{
		if (big > (int)a->content)
			return (0);
		big = (int)a->content;
		a = a->next;
	}
	return (1);
}

int	ft_lst_is_sort_simplify(t_list *lst)
{
	int	big;

	if (!lst)
		return (0);
	big = (int)lst->content;
	while (lst)
	{
		if (big > (int)lst->content)
			return (0);
		big = (int)lst->content;
		lst = lst->next;
	}
	return (1);
}
