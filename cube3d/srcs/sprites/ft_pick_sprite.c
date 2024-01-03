/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:54:57 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/17 14:39:16 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	*ft_pick_sprite(t_data data, int number_sprites)
{
	t_sprite	*sprite;
	int			i;
	int			j;
	int			sprite_i;

	i = 0;
	j = 0;
	sprite_i = 0;
	if (!(sprite = malloc(sizeof(t_sprite) * (number_sprites))))
		ft_error_msg_perso("MALLOC ERROR\n", &data);
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == '2')
			{
				sprite[sprite_i].x = i + 0.5;
				sprite[sprite_i++].y = j + 0.5;
			}
			j++;
		}
		i++;
	}
	return (sprite);
}

int			ft_count_sprite(t_data data)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_sprite	*ft_sort_sprite(t_sprite *sprite, int number_sprites)
{
	int			i;
	t_sprite	tmp;

	i = 0;
	while (i + 1 < number_sprites)
	{
		if (sprite[i].dist < sprite[i + 1].dist)
		{
			tmp = sprite[i];
			sprite[i] = sprite[i + 1];
			sprite[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (sprite);
}
