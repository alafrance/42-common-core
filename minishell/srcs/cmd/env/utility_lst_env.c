/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_lst_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:38:18 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 14:22:37 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_lstlast_env(t_env *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lst_remove_key(t_env **env, char *key)
{
	t_env	*begin;

	begin = *env;
	if (!ft_strcmp((*env)->key, key))
	{
		*env = (*env)->next;
		return ;
	}
	while (*env && (*env)->next)
	{
		if (!ft_strcmp((*env)->next->key, key))
		{
			(*env)->next = (*env)->next->next;
			*env = begin;
			return ;
		}
		*env = (*env)->next;
	}
	*env = begin;
}

t_env	*ft_keyshr(t_env *env, char *key)
{
	while (env)
	{
		if (!ft_strcmp(env->key, key))
			return (env);
		env = env->next;
	}
	return (NULL);
}
