/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:23:13 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/24 10:29:01 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_path_sprite(char **line_split, t_data *data)
{
	if (!ft_path_texture_valid(line_split, data, data->path_sprite))
		return ;
	data->path_sprite = ft_strdup(line_split[1]);
}

void	ft_color(char **line_split, t_data *data, char *color)
{
	int		i;
	int		count;
	char	**color_split;

	count = 0;
	i = 0;
	ft_error_data(line_split, data, color);
	color_split = ft_split(line_split[1], ',');
	if (ft_strslen(color_split) != 3 || ft_count_str(line_split[1], ',') != 2)
	{
		free_all(color_split, ft_strslen(color_split));
		ft_error_msg_perso("Wrong Format of color: R,G,B", data);
	}
	while (color_split[i])
	{
		if (ft_atoi(color_split[i]) < 0 || ft_atoi(color_split[i]) > 255
			|| !ft_is_number_str(color_split[i]))
		{
			free_all(color_split, ft_strslen(color_split));
			ft_error_msg_perso("Wrong number for color, between 0-255", data);
		}
		i++;
	}
	free_all(color_split, ft_strslen(color_split));
}

void	ft_color_roof(char **line_split, t_data *data)
{
	ft_color(line_split, data, data->color_roof);
	data->color_roof = ft_strdup(line_split[1]);
}

void	ft_color_floor(char **line_split, t_data *data)
{
	ft_color(line_split, data, data->color_floor);
	data->color_floor = ft_strdup(line_split[1]);
}

void	ft_resolution(char **line_split, t_data *data)
{
	if (ft_strslen(line_split) != 3)
		ft_error_msg(79, data);
	if (data->resolution[0] != 0 || data->resolution[1] != 0)
		ft_error_msg_perso("Duplicate Data", data);
	data->resolution[0] = ft_atoi(line_split[1]);
	data->resolution[1] = ft_atoi(line_split[2]);
	if (data->resolution[0] <= 0 || data->resolution[1] <= 0)
		ft_error_msg_perso("Error Resolution", data);
}
