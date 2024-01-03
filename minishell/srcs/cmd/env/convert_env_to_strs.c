/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env_to_strs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:24:44 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 15:32:42 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstsize_env_status(t_env *env, t_status status)
{
	int	i;

	i = 0;
	while (env)
	{
		if (env->status == status)
			i++;
		env = env->next;
	}
	return (i);
}

char	**convert_env_to_strs(t_list **gc, t_env *env)
{
	char	**strs_env;
	int		i;

	i = 0;
	strs_env = malloc_gc(gc, sizeof(char *) * \
			(ft_lstsize_env_status(env, status_env) + 1));
	while (env)
	{
		if (env->status == status_env)
		{
			strs_env[i] = ft_strjoin(env->key, "=");
			strs_env[i] = ft_strjoin_free(strs_env[i], env->content);
			ft_lstadd_front(gc, ft_lstnew(strs_env[i]));
			i++;
		}
		env = env->next;
	}
	strs_env[i] = NULL;
	return (strs_env);
}
