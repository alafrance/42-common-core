/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_lst_linked.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:19:54 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 15:36:28 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_lstnew_env(char *key, char *content, t_status status)
{
	t_env	*elem;

	elem = malloc(sizeof(t_env));
	if (!elem)
		return (NULL);
	elem->key = key;
	elem->content = content;
	elem->status = status;
	elem->next = NULL;
	return (elem);
}

void	ft_lstadd_back_env(t_env **alst, t_env *new)
{
	t_env	*last;

	last = ft_lstlast_env(*alst);
	if (last != NULL)
		last->next = new;
	else
		*alst = new;
}

void	ft_lstadd_linked_env(t_all **a)
{
	t_env	*new_elem;

	new_elem = ft_lstnew_env("?", "0", status_none);
	ft_lstadd_back_env(&(*a)->env, new_elem);
	ft_lstadd_front(&(*a)->gc, ft_lstnew(new_elem));
}
