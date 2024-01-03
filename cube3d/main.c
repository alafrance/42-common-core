/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:58:45 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/24 10:26:53 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fix_resolution_data(t_data *data, t_window window)
{
	int width_max;
	int height_max;

	mlx_get_screen_size(window.mlx, &width_max, &height_max);
	data->resolution[0] = closest_multiple_of_x(data->resolution[0], 64);
	data->resolution[1] = closest_multiple_of_x(data->resolution[1], 64);
	if (data->resolution[0] > width_max)
		data->resolution[0] = width_max;
	if (data->resolution[1] > height_max)
		data->resolution[1] = height_max;
}

void	launch_minilibx(t_window window, t_tab ar_s)
{
	mlx_hook(window.mlx_win, 2, 0, ft_event_pressed, &ar_s);
	mlx_hook(window.mlx_win, 3, 0, ft_event_released, &ar_s);
	mlx_hook(window.mlx_win, 17, 0L, ft_close_window, &ar_s);
	mlx_loop_hook(window.mlx, ft_loop_hook, &ar_s);
	mlx_loop(window.mlx);
}

void	ft_init_general_main(t_tab *ar_s)
{
	fix_resolution_data(&ar_s->data, ar_s->window);
	ar_s->window.number_sprites = ft_count_sprite(ar_s->data);
	ar_s->window.sprite = ft_pick_sprite(ar_s->data,
						ar_s->window.number_sprites);
	ar_s->window.mlx = mlx_init();
	ar_s->window.mlx_win = mlx_new_window(ar_s->window.mlx,
						ar_s->data.resolution[0],
						ar_s->data.resolution[1], "CUB3D");
	init_ray_data_before(&ar_s->ray_data, ar_s->data);
	init_button(&ar_s->key);
}

int		main(int ac, char **av)
{
	int		fd;
	t_tab	ar_s;

	init_data(&ar_s.data);
	if (ac == 1)
		return (ft_error_msg(22, &ar_s.data));
	fd = open(av[1], O_RDWR);
	if (fd <= 0 || !ft_is_format(av[1], ".cub"))
		return (ft_error_msg(22, &ar_s.data));
	ft_parsing(fd, &ar_s.data);
	ft_init_general_main(&ar_s);
	if (ac >= 3)
	{
		if (ac == 3 && !ft_strcmp(av[2], "--save"))
			return (ft_bmp(&ar_s));
		else
			return (ft_error_msg(22, &ar_s.data));
	}
	ft_refresh_raycasting(&ar_s, 1);
	launch_minilibx(ar_s.window, ar_s);
	close(fd);
	free_struct(&ar_s.data);
	if (ar_s.window.sprite)
		free(ar_s.window.sprite);
	return (1);
}
