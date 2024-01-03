/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:27:42 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/21 15:39:20 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*gc;

	a = NULL;
	b = NULL;
	gc = NULL;
	parse_number(ac, av, &a, &gc);
	if (a)
		push_swap(&a, &b, &gc);
	ft_lstclear(&gc, free);
	return (0);
}
