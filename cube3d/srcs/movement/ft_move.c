/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:54:25 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/17 16:18:28 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(t_tab *ar_s, double after_pos_x, double after_pos_y)
{
	if (ar_s->data.map[(int)after_pos_x][(int)ar_s->data.pos_player[1]] != '1')
		ar_s->data.pos_player[0] = after_pos_x;
	if (ar_s->data.map[(int)ar_s->data.pos_player[0]][(int)after_pos_y] != '1')
		ar_s->data.pos_player[1] = after_pos_y;
}

void	ft_move_up(t_tab *ar_s, double move_speed)
{
	double	after_pos_x;
	double	after_pos_y;

	after_pos_x = ar_s->data.pos_player[0] + ar_s->ray_data.dir[0]
					* move_speed;
	after_pos_y = ar_s->data.pos_player[1] + ar_s->ray_data.dir[1]
					* move_speed;
	ft_move(ar_s, after_pos_x, after_pos_y);
}

void	ft_move_down(t_tab *ar_s, double move_speed)
{
	double after_pos_x;
	double after_pos_y;

	after_pos_x = ar_s->data.pos_player[0] - ar_s->ray_data.dir[0]
					* move_speed;
	after_pos_y = ar_s->data.pos_player[1] - ar_s->ray_data.dir[1]
					* move_speed;
	ft_move(ar_s, after_pos_x, after_pos_y);
}

void	ft_move_right(t_tab *ar_s, double move_speed)
{
	double	after_pos_x;
	double	after_pos_y;

	after_pos_x = ar_s->data.pos_player[0] - ar_s->ray_data.dir[1]
					* move_speed;
	after_pos_y = ar_s->data.pos_player[1] + ar_s->ray_data.dir[0]
					* move_speed;
	ft_move(ar_s, after_pos_x, after_pos_y);
}

void	ft_move_left(t_tab *ar_s, double move_speed)
{
	double after_pos_x;
	double after_pos_y;

	after_pos_x = ar_s->data.pos_player[0] + ar_s->ray_data.dir[1]
					* move_speed;
	after_pos_y = ar_s->data.pos_player[1] - ar_s->ray_data.dir[0]
					* move_speed;
	ft_move(ar_s, after_pos_x, after_pos_y);
}
