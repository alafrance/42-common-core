/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:46:25 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/24 09:50:06 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_refresh_raycasting(t_tab *ar_struct, int is_display)
{
	ft_init_window_after(&ar_struct->window, ar_struct->data);
	ft_raycasting(ar_struct->data, &ar_struct->ray_data, ar_struct->window);
	ft_put_sprite(ar_struct);
	if (is_display)
		mlx_put_image_to_window(ar_struct->window.mlx,
		ar_struct->window.mlx_win, ar_struct->window.img.img, 0, 0);
	if (ar_struct->ray_data.zbuffer)
		free(ar_struct->ray_data.zbuffer);
	mlx_destroy_image(ar_struct->window.mlx, ar_struct->window.img.img);
}

void	ft_raycasting(t_data data, t_ray *ray_data, t_window window)
{
	int column;

	column = -1;
	if (!(ray_data->zbuffer = malloc(sizeof(double) * data.resolution[0])))
		ft_error_msg_perso("MALLOC ERROR\n", &data);
	while (++column < data.resolution[0])
	{
		init_ray_data_after(data, ray_data);
		*ray_data = calculate_distance(data, *ray_data, column);
		ft_calculate_draw_marge(ray_data, data);
		ft_choose_texture(&window, *ray_data);
		ft_calculate_texture(ray_data, *window.texture_used, data);
		ft_display_column(window, ray_data, data, column);
		ray_data->zbuffer[column] = ray_data->dist;
	}
}

void	ft_calculate_draw_marge(t_ray *ray_data, t_data data)
{
	ray_data->h_wall = (int)(data.resolution[1] / ray_data->dist);
	ray_data->draw[0] = -ray_data->h_wall / 2 + data.resolution[1] / 2;
	if (ray_data->draw[0] < 0)
		ray_data->draw[0] = 0;
	ray_data->draw[1] = ray_data->h_wall / 2 + data.resolution[1] / 2;
	if (ray_data->draw[1] >= data.resolution[1])
		ray_data->draw[1] = data.resolution[1] - 1;
}

void	ft_choose_texture(t_window *window, t_ray ray_data)
{
	if (ray_data.ray_dir[0] < 0 && ray_data.side == 0)
		window->texture_used = &window->n_texture;
	else if (ray_data.ray_dir[0] > 0 && ray_data.side == 0)
		window->texture_used = &window->s_texture;
	else if (ray_data.ray_dir[1] > 0 && ray_data.side == 1)
		window->texture_used = &window->e_texture;
	else if (ray_data.ray_dir[1] < 0 && ray_data.side == 1)
		window->texture_used = &window->w_texture;
}

int		ft_close_window(t_tab *ar_s)
{
	ft_close(1, &(ar_s->data));
	return (1);
}
