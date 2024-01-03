/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:49:06 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/24 10:01:21 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_header_bmp(t_fileheader *header, t_data data)
{
	header->image_size = ((data.resolution[0]) * 4)
						* data.resolution[1];
	header->file_size = header->image_size + 54;
	header->header_size = 54;
	header->bytes_size = 40;
	header->planes = 1;
	header->bytes_number = 32;
	ft_memmove(header->header, "BM", 2);
	ft_memmove(header->header + 2, &header->file_size, 4);
	ft_memmove(header->header + 10, &header->header_size, 4);
	ft_memmove(header->header + 14, &header->bytes_size, 4);
	ft_memmove(header->header + 18, &data.resolution[0], 4);
	ft_memmove(header->header + 22, &data.resolution[1], 4);
	ft_memmove(header->header + 26, &header->planes, 4);
	ft_memmove(header->header + 28, &header->bytes_number, 4);
	ft_memmove(header->header + 34, &header->image_size, 4);
}

int		ft_bmp(t_tab *ar_s)
{
	int				fd;
	int				i;
	t_fileheader	*header;

	if (!(header = malloc(sizeof(header))))
		return (ft_error_msg_perso("Malloc error", &ar_s->data));
	ft_refresh_raycasting(ar_s, 0);
	i = ar_s->data.resolution[1];
	fd = open("cub3d.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	ft_init_header_bmp(header, ar_s->data);
	write(fd, header->header, 54);
	while (i != 0)
		write(fd, (int *)ar_s->window.img.addr + (i-- *
			ar_s->data.resolution[0]), ar_s->data.resolution[0] * 4);
	close(fd);
	free_struct(&ar_s->data);
	free(header);
	if (ar_s->window.sprite)
		free(ar_s->window.sprite);
	return (1);
}
