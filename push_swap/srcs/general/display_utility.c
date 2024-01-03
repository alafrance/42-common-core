/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 09:09:09 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/08 15:20:05 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_text_center(char *text)
{
	ft_printf("|");
	ft_display_repeat(' ', (SIZE_ARRAY - ft_strlen(text)) / 2 + 1);
	ft_printf("%s", text);
	ft_display_repeat(' ', (SIZE_ARRAY - ft_strlen(text)) / 2);
}

void	display_line_empty(void)
{
	ft_printf("|");
	ft_display_repeat(' ', SIZE_ARRAY);
	ft_printf("|");
	ft_display_repeat(' ', SIZE_ARRAY);
	ft_printf("|\n");
}
