/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:27:38 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/24 10:28:05 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "struct_bmp.h"
# include "global_var.h"
# include "struct.h"
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdio.h>

void			ft_parsing(int fd, t_data *data);
int				fill_struct_parsing(char *line, t_data *data);
void			init_data(t_data *data);
int				fill_struct_parsing(char *line, t_data *data);
int				fill_struct_parsing_texture(char **line_split, t_data *data);
int				map_line_is_valid(char *map_line);
int				struct_is_valid(t_data data);
void			ft_close(int bool, t_data *data);
int				ft_error_msg(int errnum, t_data *data);
int				ft_error_msg_perso(char *error_msg, t_data *data);
int				ft_path_texture_valid(char **line_split
				, t_data *data, char *texture);
void			ft_path_ntexture(char **line_split, t_data *data);
void			ft_path_stexture(char **line_split, t_data *data);
void			ft_path_wtexture(char **line_split, t_data *data);
void			ft_path_etexture(char **line_split, t_data *data);
void			ft_path_sprite(char **line_split, t_data *data);
void			ft_color_floor(char **line_split, t_data *data);
void			ft_color_roof(char **line_split, t_data *data);
void			ft_color(char **line_split, t_data *data, char *color);
void			ft_resolution(char **line_split, t_data *data);
int				ft_is_format(char *filename, char *extension);
int				fill_struct_parsing(char *line, t_data *data);
void			free_struct(t_data *data);
int				is_only_num_and_comma(char *str);
void			ft_error_data(char **line_split, t_data *data, char *data_str);
int				ft_is_number_str(char *str);
void			ft_print_strs(char **strs);
void			ft_print_struct(t_ray data, t_data data_map);
void			ft_check_map(t_data *data);
void			ft_check_map_characters_and_pos(char **map, t_data *data);
void			ft_check_hole_in_wall(char **map, int i, int j, t_data *data);
void			miss_element(t_data *data);
void			ft_raycasting(t_data data, t_ray *ray_data, t_window window);
t_ray			calculate_distance(t_data data, t_ray ray_data, int i);
void			until_wall_is_hit(t_data data, t_ray *ray_data);
void			init_step_and_eucli_dist(t_data data, t_ray *ray_data);
void			calculate_max_map(t_data *data);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
void			ft_display_column(t_window window, t_ray *ray_data, t_data data
				, int column);
void			ft_init_window_after(t_window *window, t_data data);
void			ft_refresh_raycasting(t_tab *ar_struct, int is_display);
void			init_ray_data_before(t_ray *ray_data, t_data data);
void			init_ray_data_after(t_data data, t_ray *ray_data);
int				change_color_in_hexa(char *color);
int				ft_event_pressed(int keycode, t_tab *ar_s);
int				ft_event_released(int keycode, t_tab *ar_s);
int				ft_close_window(t_tab *ar_s);
void			ft_move(t_tab *ar_s, double after_pos_x, double after_pos_y);
int				ft_loop_hook(t_tab *ar_s);
void			ft_move_up(t_tab *ar_s, double move_speed);
void			ft_move_down(t_tab *ar_s, double move_speed);
void			ft_move_left(t_tab	*ar_s, double move_speed);
void			ft_move_right(t_tab *ar_s, double move_speed);
void			ft_rotate(t_tab *ar_s, double rot_speed);
void			ft_rotate_left(t_tab *ar_s, double rot_speed);
void			ft_rotate_right(t_tab *ar_s, double rot_speed);
void			init_tab_ar_s(t_tab *ar_s, t_ray ray_data, t_data data
								, t_window window);
void			ft_calculate_texture(t_ray *ray_data, t_img texture,
				t_data data);
void			ft_open_file(t_img *texture, void *mlx, char *path_texture);
void			ft_initializer_minilibx(t_window window, t_tab ar_s);
void			ft_calculate_draw_marge(t_ray *ray_data, t_data data);
void			ft_choose_texture(t_window *window, t_ray ray_data);
void			ft_put_sprite(t_tab *a);
int				ft_count_sprite(t_data data);
t_sprite		*ft_pick_sprite(t_data data, int number_sprites);
void			init_button(t_key *key);
void			ft_print_sprite(t_sprite sprite);
t_sprite		*ft_sort_sprite(t_sprite *sprite, int number_sprites);
void			fix_resolution_data(t_data *data, t_window window);
int				closest_multiple_of_x(int number, int x);
void			ft_init_general_main(t_tab *ar_s);
int				ft_bmp(t_tab *ar_s);
void			ft_calculate_delta_dist(t_ray *ray_data);
void			ft_print_sprite_on_screen_reduce(t_sprite sprite, t_tab *a,
				int i, int texx);
void			ft_print_sprite_on_screen(t_sprite sprite, t_tab *a);
int				ft_count_str(char *str, char c);

#endif
