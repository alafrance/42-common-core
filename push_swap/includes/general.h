/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:16:56 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/14 08:21:28 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H
# define SIZE_ARRAY 14
# include "../libft/libft.h"
# include "color.h"
# include <limits.h>
# include <stdio.h>

/*
** DISPLAY STACK
*/
void	display_stack(t_list *a, t_list *b);
void	display_text_center(char *text);
void	display_line_empty(void);
/*
** PARSE
*/
void	parse_number(int ac, char **av, t_list **a, t_list **gc);
/*
** ERROR
*/
int		ft_error(t_list *gc);
/*
**	INSTRUCTIONS
*/
void	swap_list(t_list **lst);
void	swap_a(t_list **a, t_list **b, int is_print);
void	swap_b(t_list **a, t_list **b, int is_print);
void	swap_a_b(t_list **a, t_list **b, int is_prin);
void	push_list(t_list **add, t_list **remove);
void	push_a(t_list **a, t_list **b, int is_print);
void	push_b(t_list **a, t_list **b, int is_print);
void	reverse_rotate_list(t_list **lst);
void	reverse_rotate_a(t_list **a, t_list **b, int is_print);
void	reverse_rotate_b(t_list **a, t_list **b, int is_print);
void	reverse_rotate_a_b(t_list **a, t_list **b, int is_print);
void	rotate_list(t_list **lst);
void	rotate_a(t_list **a, t_list **b, int is_print);
void	rotate_b(t_list **a, t_list **b, int is_print);
void	rotate_a_b(t_list **a, t_list **b, int is_print);
/*
**	GARBAGE COLLECTOR
*/
void	ft_print_garbage_collector(t_list *gc);
void	ft_strdup_gc(t_list **gc, char **dest, char *src);
void	*malloc_gc(t_list **gc, size_t size);
/*
**	IS_SORT
*/
int		ft_lst_is_sort(t_list *a, t_list *b);
int		ft_lst_is_sort_simplify(t_list *lst);
/*
**	TMP FUNCTION FOR DEBUG
*/
void	ft_print_struct_int(t_list *lst);
void	ft_print_struct_str(t_list *lst);
#endif