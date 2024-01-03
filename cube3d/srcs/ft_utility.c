/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:14:13 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/24 10:29:18 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_struct(t_data *data)
{
	if (data->map)
		free_all(data->map, ft_strslen(data->map));
	if (data->path_ntexture)
		free(data->path_ntexture);
	if (data->path_stexture)
		free(data->path_stexture);
	if (data->path_wtexture)
		free(data->path_wtexture);
	if (data->path_etexture)
		free(data->path_etexture);
	if (data->path_sprite)
		free(data->path_sprite);
	if (data->color_floor)
		free(data->color_floor);
	if (data->color_roof)
		free(data->color_roof);
}

int		ft_is_number_str(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_format(char *filename, char *extension)
{
	int i;

	i = ft_strlen(filename) - 1;
	if (i <= 3 || ft_strlen(extension) != 4)
		return (0);
	if (filename[i] == extension[3] &&
		filename[i - 1] == extension[2] && filename[i - 2] == extension[1]
		&& filename[i - 3] == extension[0])
		return (1);
	return (0);
}

int		closest_multiple_of_x(int number, int x)
{
	while (number % x != 0)
		number++;
	return (number);
}

int		ft_count_str(char *str, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
		if (str[i++] == c)
			count++;
	return (count);
}
