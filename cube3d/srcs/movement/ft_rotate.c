/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:08:42 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/17 16:18:35 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate_left(t_tab *ar_s, double rot_speed)
{
	ft_rotate(ar_s, -rot_speed);
}

void	ft_rotate_right(t_tab *ar_s, double rot_speed)
{
	ft_rotate(ar_s, rot_speed);
}

void	ft_rotate(t_tab *ar_s, double rot_speed)
{
	double old_dir;

	old_dir = ar_s->ray_data.dir[0];
	ar_s->ray_data.dir[0] = ar_s->ray_data.dir[0] * cos(rot_speed)
							- ar_s->ray_data.dir[1] * sin(rot_speed);
	ar_s->ray_data.dir[1] = old_dir * sin(rot_speed) +
							ar_s->ray_data.dir[1] * cos(rot_speed);
	ar_s->ray_data.plane[0] = ar_s->ray_data.dir[1] * 0.66;
	ar_s->ray_data.plane[1] = -ar_s->ray_data.dir[0] * 0.66;
}
