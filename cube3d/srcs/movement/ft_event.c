/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:23:23 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/17 16:19:30 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_event_pressed(int keycode, t_tab *ar_s)
{
	if (keycode == KEY_W)
		ar_s->key.key_w = 1;
	else if (keycode == KEY_S)
		ar_s->key.key_s = 1;
	else if (keycode == KEY_A)
		ar_s->key.key_a = 1;
	else if (keycode == KEY_D)
		ar_s->key.key_d = 1;
	else if (keycode == KEY_UP)
		ar_s->key.key_up = 1;
	else if (keycode == KEY_DOWN)
		ar_s->key.key_down = 1;
	else if (keycode == KEY_LEFT)
		ar_s->key.key_left = 1;
	else if (keycode == KEY_RIGHT)
		ar_s->key.key_right = 1;
	else if (keycode == 53)
		ft_close_window(ar_s);
	else
		return (0);
	return (1);
}

int		ft_event_released(int keycode, t_tab *ar_s)
{
	if (keycode == KEY_W)
		ar_s->key.key_w = 0;
	else if (keycode == KEY_S)
		ar_s->key.key_s = 0;
	else if (keycode == KEY_A)
		ar_s->key.key_a = 0;
	else if (keycode == KEY_D)
		ar_s->key.key_d = 0;
	else if (keycode == KEY_UP)
		ar_s->key.key_up = 0;
	else if (keycode == KEY_DOWN)
		ar_s->key.key_down = 0;
	else if (keycode == KEY_LEFT)
		ar_s->key.key_left = 0;
	else if (keycode == KEY_RIGHT)
		ar_s->key.key_right = 0;
	return (0);
}

int		ft_loop_hook(t_tab *ar_s)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.09;
	rot_speed = 0.06;
	if (ar_s->key.key_w || ar_s->key.key_up)
		ft_move_up(ar_s, move_speed);
	if (ar_s->key.key_s || ar_s->key.key_down)
		ft_move_down(ar_s, move_speed);
	if (ar_s->key.key_d)
		ft_move_left(ar_s, move_speed);
	if (ar_s->key.key_a)
		ft_move_right(ar_s, move_speed);
	if (ar_s->key.key_left)
		ft_rotate_left(ar_s, rot_speed);
	if (ar_s->key.key_right)
		ft_rotate_right(ar_s, rot_speed);
	ft_refresh_raycasting(ar_s, 1);
	return (1);
}
