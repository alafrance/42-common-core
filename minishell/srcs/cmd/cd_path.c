/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:52:32 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 15:55:53 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_old_pwd(t_all *a)
{
	t_env	*env;
	char	*old_pwd;
	char	*pwd;

	pwd = ft_content_shr(a->env, "PWD");
	if (pwd != NULL)
	{
		old_pwd = malloc_gc(&a->gc, sizeof(char) * ft_strlen(pwd) + 1);
		ft_strcpy(old_pwd, pwd);
		env = ft_keyshr(a->env, "OLDPWD");
		if (env)
			env->content = old_pwd;
	}
}

void	update_path(char **path, int *ret, t_all *a)
{
	if (*path && !ft_strncmp("-", *path, 2))
	{
		if (ft_content_shr(a->env, "OLDPWD") == NULL)
			ft_printf(1, "OLDPWD not set\n");
		else
			*ret = chdir(ft_content_shr(a->env, "OLDPWD"));
		ft_init_old_pwd(a);
	}
	else if (*path == NULL || (!ft_strncmp("~", *path, 2)))
	{
		ft_init_old_pwd(a);
		if (ft_content_shr(a->env, "HOME") != NULL)
			*ret = chdir(ft_content_shr(a->env, "HOME"));
	}
	else
	{
		ft_init_old_pwd(a);
		*ret = chdir(*path);
	}
}
