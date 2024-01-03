/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:57:24 by alafranc          #+#    #+#             */
/*   Updated: 2021/01/13 19:16:21 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_path_ntexture(char **line_split, t_data *data)
{
	if (!ft_path_texture_valid(line_split, data, data->path_ntexture))
		return ;
	data->path_ntexture = ft_strdup(line_split[1]);
}

void	ft_path_stexture(char **line_split, t_data *data)
{
	if (!ft_path_texture_valid(line_split, data, data->path_stexture))
		return ;
	data->path_stexture = ft_strdup(line_split[1]);
}

void	ft_path_wtexture(char **line_split, t_data *data)
{
	if (!ft_path_texture_valid(line_split, data, data->path_wtexture))
		return ;
	data->path_wtexture = ft_strdup(line_split[1]);
}

void	ft_path_etexture(char **line_split, t_data *data)
{
	if (!ft_path_texture_valid(line_split, data, data->path_etexture))
		return ;
	data->path_etexture = ft_strdup(line_split[1]);
}

int		ft_path_texture_valid(char **line_split, t_data *data, char *texture)
{
	int fd;

	if (ft_strslen(line_split) != 2)
		ft_error_msg(79, data);
	fd = open(line_split[1], O_RDONLY);
	if (!ft_is_format(line_split[1], ".xpm"))
	{
		free_all(line_split, ft_strslen(line_split));
		return (ft_error_msg_perso("Wrong Extension. Only XPM", data));
	}
	if (texture != NULL || fd == -1)
	{
		free_all(line_split, ft_strslen(line_split));
		if (texture != NULL)
			return (ft_error_msg_perso("Duplicate Data", data));
		return (ft_error_msg(2, data));
	}
	return (1);
}
