/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:14:02 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/08 13:02:15 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_tab(t_list *lst, t_list **gc, int size)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc_gc(gc, sizeof(int) * size);
	if (!tab)
		ft_error(*gc);
	while (lst)
	{
		tab[i++] = (int)lst->content;
		lst = lst->next;
	}
	return (tab);
}

int	*sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i + 1 < size)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			if (i != 0)
				i--;
		}
		else
			i++;
	}
	return (tab);
}
