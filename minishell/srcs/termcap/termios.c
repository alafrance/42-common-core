/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:47:01 by alafranc          #+#    #+#             */
/*   Updated: 2021/05/28 11:48:54 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

struct termios	get_termios(void)
{
	struct termios	saved;

	tcgetattr(STDIN_FILENO, &saved);
	return (saved);
}

void	apply_termios(struct termios termios)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &termios);
}
