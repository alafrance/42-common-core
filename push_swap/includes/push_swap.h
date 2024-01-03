/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:36:43 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/20 14:10:44 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "general.h"

/*
**	PUSH_SWAP
*/
void	push_swap(t_list **a, t_list **b, t_list **gc);
/*
**	FIND NUMBER
*/
int		ft_minimum_number(t_list *a);
int		ft_maximum_number(t_list *b);
int		ft_sqrt_int(int nb);
/*
**	CREATE REFERENCE TAB
*/
int		*create_tab(t_list *lst, t_list **gc, int size);
int		*sort_int_tab(int *tab, int size);
/*
**	ALGO SORT 3
*/
void	algo_sort_3(int count, t_list **lst);
/*
**	ALGO SORT 5
*/
void	push_minimun_b(t_list **a, t_list **b);
void	algo_sort_5(int count, t_list **a, t_list **b);
/*
**	ALGO SORT
*/
void	push_between_bounds(t_list **a, t_list **b,
			int bound_min, int bound_max);
void	push_max_a(t_list **a, t_list **b);
void	algo_sort(t_list **a, t_list **b, t_list **gc);
#endif