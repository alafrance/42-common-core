/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:59:28 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/08 15:38:49 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	init_gnl(int fd, char **line)
{
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_calloc(1, BUFFER_SIZE + 1);
	if (!(*line))
		return (-1);
	return (1);
}

static void	ft_crop_buffer(char *buffer, int i_b)
{
	int	i;

	i = 0;
	if (i_b < BUFFER_SIZE + 1)
	{
		while (buffer[i_b + i])
		{
			buffer[i] = buffer[i_b + i];
			i++;
		}
	}
	while (i < BUFFER_SIZE + 1)
		buffer[i++] = '\0';
}

static int	ft_buffer_to_line(char **line, char *buffer)
{
	int	i;
	int	end_line;

	i = 0;
	end_line = 2;
	while (buffer[i] != '\n' && buffer[i])
	{
		(*line)[i] = buffer[i];
		i++;
	}
	(*line)[i] = '\0';
	if (buffer[i] == '\n')
		end_line = 1;
	ft_crop_buffer(buffer, i + 1);
	return (end_line);
}

static int	ft_add_line(char **line, char *buffer)
{
	int		end_line;
	int		i_l;
	int		i_b;
	char	*str_temp;

	i_l = -1;
	i_b = 0;
	end_line = 0;
	str_temp = *line;
	*line = ft_calloc(1, ft_strlen(*line) + BUFFER_SIZE + 1);
	if (!(*line))
		return (free_error_gnl(str_temp));
	while ((str_temp)[++i_l])
		(*line)[i_l] = str_temp[i_l];
	while (buffer[i_b] != '\n' && buffer[i_b])
	{
		(*line)[i_l + i_b] = buffer[i_b];
		i_b++;
	}
	if (buffer[i_b] == '\n')
		end_line = 1;
	ft_crop_buffer(buffer, i_b + 1);
	free(str_temp);
	return (end_line);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[4096][BUFFER_SIZE + 1];
	int			size;
	int			response_add_line;

	if (init_gnl(fd, line) == -1)
		return (-1);
	if (buffer[fd][0])
		if (ft_buffer_to_line(line, buffer[fd]) == 1)
			return (1);
	size = 1;
	ft_bzero(buffer[fd], BUFFER_SIZE + 1);
	while (size > 0)
	{
		size = read(fd, buffer[fd], BUFFER_SIZE);
		if (size == -1)
			return (-1);
		response_add_line = ft_add_line(line, buffer[fd]);
		if (response_add_line)
			return (response_add_line);
	}
	if (!size)
		return (0);
	return (1);
}
