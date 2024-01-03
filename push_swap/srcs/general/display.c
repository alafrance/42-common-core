/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 07:32:47 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/08 15:23:08 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_display_list(t_list **elem, char *color)
{
	int	size_n;

	if (*elem)
	{
		size_n = ft_size_nb(ft_abs((int)(*elem)->content), 10);
		if ((int)(*elem)->content < 0)
			size_n ++;
	}
	else
		size_n = 0;
	if (ft_even(size_n))
		ft_display_repeat(' ', (SIZE_ARRAY - size_n) / 2);
	else
		ft_display_repeat(' ', (SIZE_ARRAY - size_n) / 2);
	if (*elem)
	{
		ft_printf("%s%d%s", color, (int)(*elem)->content, RESET);
		*elem = (*elem)->next;
	}
	if (ft_even(size_n))
		ft_display_repeat(' ', (SIZE_ARRAY - size_n) / 2);
	else
		ft_display_repeat(' ', (SIZE_ARRAY - size_n + 1) / 2);
	ft_printf("|");
}

static void	display_header(void)
{
	ft_printf("|");
	ft_display_repeat('-', SIZE_ARRAY * 2 + 1);
	ft_printf("|\n");
	display_text_center("TOP STACK A");
	display_text_center("TOP STACK B");
	ft_printf("|\n");
	display_line_empty();
}

static void	display_footer(void)
{
	display_line_empty();
	display_text_center("STACK A");
	display_text_center("STACK B");
	ft_printf("|\n");
	ft_printf("|");
	ft_display_repeat('-', SIZE_ARRAY * 2 + 1);
	ft_printf("|\n");
}

void	display_number(t_list *a, t_list *b)
{
	int	biggest;
	int	stop_green;

	if (a)
		biggest = (int)a->content;
	stop_green = 0;
	while (a || b)
	{
		ft_printf("|");
		if (a && !stop_green && (int)a->content >= biggest)
		{
			biggest = (int)a->content;
			ft_display_list(&a, BGRN);
		}
		else
		{
			ft_display_list(&a, BRED);
			stop_green = 1;
		}
		ft_display_list(&b, BRED);
		ft_printf("\n");
	}
}

void	display_stack(t_list *a, t_list *b)
{
	if (!a && !b)
		return ;
	display_header();
	display_number(a, b);
	display_footer();
}
