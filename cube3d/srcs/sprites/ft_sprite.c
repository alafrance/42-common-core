/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:41:02 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/16 23:42:29 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calc_height_sprite(t_sprite *sprite, t_data data)
{
	sprite->sprite_height = abs((int)((data.resolution[1] /
							sprite->transform_y))) / VDIV;
	sprite->draw_sprite_y[0] = -sprite->sprite_height / 2 + data.resolution[1]
							/ 2 + sprite->v_move_screen;
	if (sprite->draw_sprite_y < 0)
		sprite->draw_sprite_y[0] = 0;
	sprite->draw_sprite_y[1] = sprite->sprite_height / 2 + data.resolution[1] /
								2 + sprite->v_move_screen;
	if (sprite->draw_sprite_y[1] >= data.resolution[1])
		sprite->draw_sprite_y[1] = data.resolution[1] - 1;
}

void	ft_calc_width_sprite(t_sprite *sprite, t_data data)
{
	sprite->sprite_width = abs((int)((data.resolution[1] /
						sprite->transform_y))) / UDIV;
	sprite->draw_sprite_x[0] = -sprite->sprite_width / 2 +
								sprite->sprite_screen_x;
	if (sprite->draw_sprite_x[0] < 0)
		sprite->draw_sprite_x[0] = 0;
	sprite->draw_sprite_x[1] = sprite->sprite_width / 2 +
								sprite->sprite_screen_x;
	if (sprite->draw_sprite_x[1] >= data.resolution[0])
		sprite->draw_sprite_x[1] = data.resolution[0] - 1;
}

void	ft_init_sprite(t_sprite *sprite, t_ray ray_data, t_data data)
{
	sprite->x_relative = sprite->x - data.pos_player[0];
	sprite->y_relative = sprite->y - data.pos_player[1];
	sprite->inv_det = 1.0 / (ray_data.plane[0] * ray_data.dir[1] -
					ray_data.dir[0] * ray_data.plane[1]);
	sprite->transform_x = sprite->inv_det * (ray_data.dir[1] *
						sprite->x_relative
						- ray_data.dir[0] * sprite->y_relative);
	sprite->transform_y = sprite->inv_det * (-ray_data.plane[1] *
						sprite->x_relative + ray_data.plane[0] *
						sprite->y_relative);
	sprite->sprite_screen_x = (int)(data.resolution[0] / 2) * (1 +
							sprite->transform_x / sprite->transform_y);
	sprite->v_move_screen = (int)(VMOVE / sprite->transform_y);
}

void	ft_put_sprite(t_tab *a)
{
	int i;

	i = -1;
	while (++i < a->window.number_sprites)
		a->window.sprite[i].dist = ft_power(a->data.pos_player[0] -
		a->window.sprite[i].x, 2) + ft_power(a->data.pos_player[1] -
		a->window.sprite[i].y, 2);
	i = 0;
	a->window.sprite = ft_sort_sprite(a->window.sprite,
						a->window.number_sprites);
	while (i < a->window.number_sprites)
	{
		ft_init_sprite(&a->window.sprite[i], a->ray_data, a->data);
		ft_calc_height_sprite(&a->window.sprite[i], a->data);
		ft_calc_width_sprite(&a->window.sprite[i], a->data);
		ft_print_sprite_on_screen(a->window.sprite[i], a);
		i++;
	}
}
