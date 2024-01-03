/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:11:02 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/28 16:39:43 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define CTRL_U 21
# define CTRL_L 12
# define DEL	127
# define BACKSPACE 8
# define CTRL_D		4
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "color.h"
# include "struct.h"
/*	---------- SRCS ---------- */
void			*malloc_gc(t_list **gc, size_t size);
char			*ft_strdup_gc(t_list **gc, char *src);
void			ft_lst_add_to_gc(t_list **gc, t_list *lst);
t_all			*set_all(t_all *tmp);
t_all			*get_all(void);
void			read_command_line(t_all *a);
t_all			*init_all(char **envp, char *name_prg);
void			print_banner(void);
int				ft_switch_keyboard(t_all *a, char buf[4],
					int *cursor, char **line);
void			ft_launch_cmd_and_reset(t_all *a, int *cursor, char **line);
void			ft_print_line_and_stock(t_all *a, char **line, char *buf,
					int *cursor);
int				ft_putchar_int(int c);
void			display_line(t_all *a);
void			ft_cmd_not_found(t_all *a, char *cmd);
void			ft_no_such_file(t_all *a, char *cmd);
void			ft_error_is_a_directory(t_all *a, char *cmd);
void			ft_error_pipe(t_all *a);
void			ft_error_msg(char *msg_error, t_list *gc);
void			ft_error_a(char *file, char *msg_error, t_all *a);
void			ft_error_input(char *file, char *msg_error, t_all *a);
int				ft_check_error(t_all *a, char *line, int *i);
void			ft_skip(char *line, int *i);
int				ft_chevron(char *line, int *i, int quote, int count);
/* ---------- TERMCAP ---------- */
/*	ARROW_KEY */
void			ft_arrow_key(t_all *a, char c, int *cursor, char **line);
void			ft_left_arrow(int *cursor);
void			ft_right_arrow(int *cursor, int size_line);
void			ft_up_arrow(t_input *term, int *cursor, char **line,
					t_list **gc);
void			ft_down_arrow(t_input *term, int *cursor, char **line,
					t_list **gc);
/*	DELETE */
char			*delete_char(int index_char, char *str, t_list **gc);
void			ft_delete_line_to_cursor(t_list **gc, int *cursor, char **line);
void			ft_delete_line_from_cursor_into_line(t_list **gc, int *cursor,
					char **line);
void			ft_delete_line(t_list **gc, int *cursor, char **line);
void			ft_backspace(t_list **gc, int *cursor, char **line);
/*	INIT */
void			init_termios(void);
void			init_terms(t_all *a);
void			ft_init_input(t_all *a);
/*	PRINT */
int				ft_print_buf(char *str, int *cursor);
void			ft_print_buf_and_stock(t_all *a, char **line, char *buf,
					int *cursor);
/*	FT_EXEC_TERMCAP */
void			stock_to_historic(t_all *a, char *line);
void			ft_exec_termcap(t_all *a, int *cursor, char **line);
void			reset_variable_termcap(t_all *a, int *cursor, char **line);
/*	READ_CMD_LINE */
void			read_command_line(t_all *a);
int				ft_switch_keyboard(t_all *a, char buf[4],
					int *cursor, char **line);
void			ft_launch_cmd_and_reset(t_all *a, int *cursor, char **line);
/*	TERMIOS */
struct termios	get_termios(void);
void			apply_termios(struct termios termios);
/*	UTILITY */
t_list			*previous_current(t_list *lst, t_list *current,
					t_list *historic_current);
void			ft_change_line(t_list **gc, int *cursor, char **line,
					char *new_line);
char			*ft_add_string_in_index(t_list **gc, char **str_split,
					char *add);
char			**split_str_into_index(t_list **gc, char *str, int index);

/*
**	---------- CMD ----------
** 		---------- ENV ----------
*/
/* UTILITY_ENV */
t_env			*ft_lstnew_env(char *key, char *content, t_status status);
t_env			*ft_lstlast_env(t_env *lst);
void			ft_lstadd_back_env(t_env **alst, t_env *new);
void			ft_lst_remove_key(t_env **env, char *key);
t_env			*ft_keyshr(t_env *env, char *key);
/* ENV_EXPORT_UNSET */
int				ft_env(t_all *a, char **args);
int				ft_export(t_all *a, char **args);
int				ft_unset(t_all *a, char **args);
int				ft_print_alphabetic_env(t_env *env);
/* CONVERT */
int				ft_lstsize_env_status(t_env *env, t_status status);
char			**convert_env_to_strs(t_list **gc, t_env *env);
/* PUSH_EXPORT */
void			push_variable_whitout_export(t_command *cmd, t_all *a);
void			declare_env_var(t_command *cmd, t_all *a);
int				push_variable_plus(char *str, t_all *a, t_status status);
int				push_variable_equal(char *str, t_all *a, t_status status);
int				check_error_export(char *str, t_env *new_elem);
/* UTILITY_LST_LINKED */
void			ft_lstadd_linked_env(t_all **a);
int				is_only_equal(char *str);
int				ft_strchr_str(char *str, char *find);

/*
** 		---------- ECHO ----------
*/
int				ft_echo(t_all *a, char **args);
void			delete_option_and_empty_quote(t_list **arg_split,
					t_all *a, int *option);
void			main_echo(char **arg_split);
int				ft_reverse_boolean(int boolean);
int				is_option(char *args);
char			*delete_backslash(t_list **gc, char *str);
/*
**		---------- ROOT ----------
*/
int				ft_exit(t_all *a, char **args);
int				ft_alexis(t_all *a, char **args);
int				ft_quentin(t_all *a, char **args);
void			ft_init_old_pwd(t_all *a);
void			update_path(char **path, int *ret, t_all *a);
char			*ft_content_shr(t_env *env, char *key);
int				ft_cd(t_all *a, char **args);
int				ft_pwd(t_all *a, char **args);
/*	
** ---------- ARGUMENT ----------
** ARG_PARSING
*/
char			**parse_argument(t_all *a, char *args);
t_env			*find_env(t_all *a, char *arg, int *i);
char			*transform_arg_with_env(char *arg, t_all *a);
/* BACKSLASH */
int				count_delete_backslash(char *str);
char			*delete_backslash(t_list **gc, char *str);
int				count_add_backslash_quote(char *str);
char			*add_backslash_quote(t_list **gc, char *str);
/* FT_SPLIT_QUOTE */
void			jump_to_next_quote(int *i, char *str, char quote);
char			**ft_split_quote(char *str, char del);
/* QUOTES */
char			*delete_empty_quote(t_list **gc, char *str);
char			*delete_quote(t_list **gc, char *args);
/* IS_BACKSLASH */
int				is_quote_or_d_quote(char *str, int index);
int				ft_is_backslash_before(char *str, int index, char c);
int				ft_ccmp(char c, char *str);
/* TRANSFORM_STR */
char			*transform_home(t_all *a, char *new_str, int *i);
char			*transform_var_env(char *arg, t_all *a, char *new_str, int *i);
char			*ft_add_char(char *arg, t_all *a, int *i, char *new_str);
char			*transform_arg_with_env(char *arg, t_all *a);
/*	
** ---------- PARSING ----------
*/
/* ENV_PARSING */
t_env			*parse_env(char **env, t_list **gc);
t_env			*pick_key_and_content(char *envp, t_list **gc,
					t_status status, int separator);
/* PARSING */
int				ft_check_cmd_after(int **array, t_tree *node, t_all *a);
void			ft_put_in_array(int **array, int *op_pos,
					t_tree *node, t_all *a);
void			ft_parsing(char *line, int *array, t_tree *node, t_all *a);
t_tree			*ft_binary_tree(char *line, int start, int end, t_all *a);
/* UTILS_PARSING */
void			ft_skip_whitespace(char *line, int *i);
int				ft_is_bs_before(char *line, int i);
void			ft_is_quote(char c, int *quote);
int				ft_delimiter(char c, char *del);
char			*ft_substr_sw(char *s, int w, size_t len);
/* CMD_PARSING */
int				ft_malloc_command(char *line, int *array,
					t_tree *node, t_all *a);
/* FILE_PARSING */
void			ft_malloc_file(char *line, int *array, t_tree *node, t_all *a);
/* PRINT */
void			ft_print_tree(t_tree *node, int count);
/* PRIORITY_OP */
void			ft_priority(char *line, int start, int end, t_tree *node);
int				*ft_op_pos(char *line, int end, t_tree *node, t_all *a);
void			ft_print_start_to_end(char *line, int start, int end);
/* REDIR_PARSING */
void			ft_malloc_redir(t_tree *node, t_all *a, int *array, char *line);
int				ft_re_size(char *line, int *i,
					int (*f)(char c, char *str), char *del);
char			*ft_strjoin_ws(char *s1, char *s2, t_all *a);
void			ft_set_ini(int *start, int *size, int beg, int end);
int				ft_check_name(int *pos, int *end, int *count, char *line);
/*	---------- EXEC ---------- */
/* FT_PARSE_AND_EXEC */
void			ft_parse_and_exec(char *line, t_all *a);
void			ft_exec_tree(t_tree *node, t_all *a);
void			ft_file(t_tree *node, t_all *a);
void			ft_pipe(t_all *a);
void			ft_redir(t_operator *op, t_all *a);
void			ft_is_another_pipe(t_tree *node, t_all *a);
/* INIT_EXEC */
void			init_redir(t_redir *redir);
void			init_pipe(t_pipe *pipe);
void			reset_pipe(t_pipe *pipe);
void			reset_redir(t_all *a);
void			ft_reset(t_all *a);
void			ft_lst_add_fd(t_all *a, int fd);
/* UTILS_EXEC */
void			ft_init_tree(t_all *a);
void			fill_env_(t_command *cmd, t_all *a);
/*		---------- EXEC_CMD ---------- */
/*	EXEC_CMD */
int				ft_is_our_cmd(t_command *cmd, char **cmd_done);
void			ft_status_cmd(t_all *a, int *status_cmd);
void			ft_exec_cmd_main(t_command *cmd, t_all *a);
void			ft_exec_cmd(t_command *cmd, t_all *a);
void			ft_is_another_cmd(t_tree *node, t_all *a);
/* FILL_PATH_CMD */
int				ft_is_a_directory(char *cmd_path);
int				ft_test_with_path(t_command *cmd, t_all *a);
void			ft_test_with_path_directly(t_command *cmd, t_all *a);
void			fill_cmd_with_path(t_command *cmd, t_all *a);
/* PTR_ARRAY_FUNCTION */
char			**list_cmd_done(t_list **gc);
void			*init_array_instruction_function(t_list **gc);
/* EXEC_CMD */
int				ft_is_our_cmd(t_command *cmd, char **cmd_done);
int				ft_exec_cmd_error(t_command *cmd, t_all *a);
void			ft_dup_for_pipe(t_all *a);
#endif
