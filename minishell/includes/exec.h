/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:44:55 by qurobert          #+#    #+#             */
/*   Updated: 2021/06/24 18:38:08 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

typedef enum e_type_enum
{
	other,
	file,
	command,
	redir,
	op_pipe
}					t_type_enum;

typedef struct s_command
{
	char			*cmd;
	char			*args;
	char			**handle_arg;
	int				our_cmd;
	int				error;
}					t_command;

typedef struct s_operator
{
	char			*op;
}					t_operator;

typedef struct s_file
{
	char			*file;
}					t_file;

typedef union u_type_union
{
	t_command		*cmd;
	t_operator		*op;
	t_file			*file;
}					t_type_union;

#endif
