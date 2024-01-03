/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:14:16 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/21 14:41:44 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_present(int nb, t_list *lst)
{
	while (lst)
	{
		if ((int)lst->content == nb)
			return (1);
		lst = lst->next;
	}
	return (0);
}

long	ft_atoi_one_number(char *str, t_list **gc)
{
	long	nb;
	int		neg;
	int		size_n;

	neg = 1;
	nb = 0;
	size_n = 0;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (ft_isdigit(*str) && *str)
	{
		nb = nb * 10 + *str - '0';
		str++;
		size_n++;
		if (size_n > 10)
			ft_error(*gc);
	}
	if ((nb == 0 && neg == -1) || *str != '\0')
		ft_error(*gc);
	nb *= neg;
	return (nb);
}

void	pick_number(char *str, t_list **a, t_list **gc)
{
	long	nb;
	char	**nb_split;
	t_list	*new_elem;
	int		i;

	i = -1;
	nb_split = ft_split(str, ' ');
	if (!nb_split)
		ft_error(*gc);
	while (nb_split[++i])
		ft_lstadd_back(gc, ft_lstnew(nb_split[i]));
	ft_lstadd_front(gc, ft_lstnew(nb_split));
	i = -1;
	while (nb_split[++i])
	{
		nb = ft_atoi_one_number(nb_split[i], gc);
		if (nb > INT_MAX || nb < INT_MIN || is_present(nb, *a))
			ft_error(*gc);
		new_elem = ft_lstnew((void *)nb);
		ft_lstadd_back(a, new_elem);
		ft_lstadd_front(gc, ft_lstnew(new_elem));
	}
}

void	parse_number(int ac, char **av, t_list **a, t_list **gc)
{
	int	i;

	i = 1;
	while (i != ac)
		pick_number(av[i++], a, gc);
}
