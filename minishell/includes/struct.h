/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:10:33 by qurobert          #+#    #+#             */
/*   Updated: 2021/06/24 10:04:04 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "exec.h"

typedef enum e_status
{
	status_env,
	status_export,
	status_none
}				t_status;

typedef struct s_env
{
	char			*key;
	char			*content;
	t_status		status;
	struct s_env	*next;
}					t_env;

typedef struct s_tree
{	
	struct s_tree	*left;
	struct s_tree	*right;
	int				type;
	t_type_enum		e_type;
	t_type_union	*exec;
	int				count;
	int				start;
	int				end;
	char			*line;
}					t_tree;

typedef struct s_input
{
	int				ctrl_c;
	struct termios	saved;
	t_list			*historic;
	t_list			*historic_current;
	t_list			*ptr_historic;
	char			**line;
	int				*cursor;
}				t_input;

typedef struct s_redir
{
	int				fd_backup;
	int				chevron;
	int				input;
	int				fd;
	int				count;
}				t_redir;

typedef struct s_pipe
{
	int				count;
	int				is_pipe;
	int				*fd_backup;
	int				backup_tmp;
	int				*fd;
}				t_pipe;

typedef struct s_fd
{
	int			content;
	struct s_fd	*next;
}				t_fd;

typedef struct s_all
{
	t_env			*env;
	t_list			*gc;
	t_tree			*tree;
	t_input			*input;
	t_pipe			*pipe;
	t_redir			*redir;
	t_fd			*fd;
	int				in_cmd;
	int				status;
	int				read;
	char			*name_prg;
}				t_all;

#endif
