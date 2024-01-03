/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:16:46 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/08 15:40:53 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "general.h"

/*
**	CHECKER
*/
void	checker(t_list **a, t_list **b, t_list **gc);
void	pick_instruction(t_list **instruction, t_list **gc);
int		is_instruction(char *str, t_list **gc);
/*
**	ARRAY INSTRUCTION
*/
char	**all_instruction_on_tab(t_list **gc);
int		is_instruction(char *str, t_list **gc);
void	*init_array_instruction_function(t_list **gc);
#endif