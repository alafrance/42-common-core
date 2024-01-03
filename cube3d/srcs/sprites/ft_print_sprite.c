/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:22:56 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/16 23:39:52 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_sprite_on_screen(t_sprite sprite, t_tab *a)
{
	int i;
	int	texx;

	i = sprite.draw_sprite_x[0];
	while (i < sprite.draw_sprite_x[1])
	{
		texx = (int)(256 * (i - (-sprite.sprite_width / 2 +
				sprite.sprite_screen_x)) * a->window.sprite_file.width /
				sprite.sprite_width) / 256;
		if (sprite.transform_y > 0 && i > 0
			&& i < a->data.resolution[0]
			&& sprite.transform_y < a->ray_data.zbuffer[i]
			&& sprite.draw_sprite_y[0] > 0)
			ft_print_sprite_on_screen_reduce(sprite, a, i, texx);
		i++;
	}
}

void	ft_print_sprite_on_screen_reduce(t_sprite sprite, t_tab *a, int i,
		int texx)
{
	int j;
	int	d;
	int	texy;
	int	color;

	j = sprite.draw_sprite_y[0];
	while (j < sprite.draw_sprite_y[1])
	{
		d = (j - sprite.v_move_screen) * 256 - a->data.resolution[1] * 128
			+ sprite.sprite_height * 128;
		texy = ((d * a->window.sprite_file.height)
			/ sprite.sprite_height) / 256;
		color = a->window.sprite_file.addr[a->window.sprite_file.width *
			texy + texx];
		if (color != 0x980088)
			a->window.img.addr[j * a->data.resolution[0] + i] = color;
		j++;
	}
}
