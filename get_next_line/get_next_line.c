/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:59:28 by alafranc          #+#    #+#             */
/*   Updated: 2020/12/01 16:54:02 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_remove_first_line(char *file)
{
	char	*buf;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (file == NULL)
		return (NULL);
	while (file[i] && file[i] != '\n')
		i++;
	if (file[i] == '\n')
		i++;
	if (!(buf = malloc(sizeof(char) * (ft_strlen(file) - i + 1))))
		return (NULL);
	while (file[i])
		buf[j++] = file[i++];
	buf[j] = '\0';
	free(file);
	return (buf);
}

char	*fill_filebuf(int fd, char *filebuf, int *b_read)
{
	char		buf[BUFFER_SIZE + 1];

	if (ft_strchr(filebuf, '\n') >= 0 || (fd == 0 && filebuf != NULL))
		return (filebuf);
	while ((*b_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[*b_read] = '\0';
		filebuf = ft_strjoin(filebuf, buf);
		if (fd != 0 && ft_strchr(filebuf, '\n') != -1)
			break ;
	}
	return (filebuf);
}

int		get_next_line(int fd, char **line)
{
	static int	b_read;
	static char *filebuf;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1 || !line)
		return (-1);
	filebuf = fill_filebuf(fd, filebuf, &b_read);
	*line = ft_substr_line(filebuf);
	filebuf = ft_remove_first_line(filebuf);
	if (filebuf == NULL || (b_read == 0 && filebuf[0] == '\0'))
		return (0);
	else
		return (1);
}
