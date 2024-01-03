/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:07:01 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/16 14:30:48 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_close(int bool, t_data *data)
{
	if (data)
		free_struct(data);
	if (bool)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

void	miss_element(t_data *data)
{
	if (!data->map)
		ft_error_msg_perso("Miss map", data);
	if (!data->path_ntexture)
		ft_error_msg_perso("Miss north texture", data);
	if (!data->path_stexture)
		ft_error_msg_perso("Miss south texture t nul", data);
	if (!data->path_wtexture)
		ft_error_msg_perso("Miss west texture", data);
	if (!data->path_etexture)
		ft_error_msg_perso("Miss east texture", data);
	if (!data->path_sprite)
		ft_error_msg_perso("Miss sprite", data);
	if (!data->color_floor)
		ft_error_msg_perso("Miss floor color", data);
	if (!data->color_roof)
		ft_error_msg_perso("Miss roof color", data);
	ft_close(0, data);
}

int		ft_error_msg(int errnum, t_data *data)
{
	ft_printf("Error\n%s\n", strerror(errnum));
	ft_close(0, data);
	return (0);
}

int		ft_error_msg_perso(char *error_msg, t_data *data)
{
	ft_printf("Error\n%s\n", error_msg);
	ft_close(0, data);
	return (0);
}

void	ft_error_data(char **line_split, t_data *data, char *data_str)
{
	if (ft_strslen(line_split) != 2)
	{
		free_all(line_split, ft_strslen(line_split));
		ft_error_msg(79, data);
	}
	if (data_str != NULL)
		ft_error_msg_perso("Duplicate Data", data);
}
