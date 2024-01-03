/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:59:04 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/17 14:35:53 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map(t_data *data)
{
	char **map;

	map = ft_strsdup(data->map);
	ft_check_map_characters_and_pos(map, data);
	ft_check_hole_in_wall(map, data->pos_player[0], data->pos_player[1], data);
	free_all(map, ft_strslen(map));
	if (!data->path_etexture || !data->path_ntexture || !data->path_sprite
		|| !data->path_stexture || !data->path_wtexture || !data->color_floor
		|| !data->color_roof || !data->resolution[0] || !data->resolution[1])
		miss_element(data);
}

void	pick_pos_player(char **map, t_data *data, int i, int j)
{
	if (ft_strchr("NSWE", map[i][j])
		&& data->pos_player[0] == -1 && data->pos_player[1] == -1)
	{
		data->pos_player[0] = i + 0.5;
		data->pos_player[1] = j + 0.5;
		data->pos_camera = map[i][j];
		map[i][j] = '0';
	}
	else
	{
		free_all(map, ft_strslen(map));
		ft_error_msg_perso("Wrong Characters Map", data);
	}
}

void	ft_check_map_characters_and_pos(char **map, t_data *data)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(ft_strchr("0123 ", map[i][j])))
				pick_pos_player(map, data, i, j);
			j++;
		}
		i++;
	}
}

void	ft_check_hole_in_wall(char **map, int i, int j, t_data *data)
{
	if (i < 0 || j < 0 || i >= ft_strslen(map) ||
		j >= (int)ft_strlen(map[i]) || map[i][j] == ' ')
		ft_error_msg_perso("Hole in Map", data);
	if (map[i][j] == '0' || map[i][j] == '2' || map[i][j] == '3')
	{
		map[i][j] = 'c';
		ft_check_hole_in_wall(map, i - 1, j, data);
		ft_check_hole_in_wall(map, i + 1, j, data);
		ft_check_hole_in_wall(map, i, j - 1, data);
		ft_check_hole_in_wall(map, i, j + 1, data);
	}
}
