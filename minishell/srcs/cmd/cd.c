/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:27:21 by qurobert          #+#    #+#             */
/*   Updated: 2021/06/24 15:55:45 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_content_shr(t_env *env, char *key)
{
	while (env)
	{
		if (!ft_strcmp(env->key, key))
			return (env->content);
		env = env->next;
	}
	return (NULL);
}

void	ft_get_path(char *arg, char **path, t_all *a)
{
	int	i;

	i = 0;
	while (arg && arg[i] && arg[i] != ' ')
		i++;
	*path = malloc_gc(&a->gc, sizeof(char) * i + 1);
	i = 0;
	while (arg && arg[i] && arg[i] != ' ')
	{
		(*path)[i] = arg[i];
		i++;
	}
	(*path)[i] = '\0';
}

int	ft_cd(t_all *a, char **arg)
{
	char	*path;
	char	*buf;
	int		ret;
	t_env	*env;

	ret = 0;
	path = 0;
	if (!arg)
		path = NULL;
	else
		ft_get_path(arg[0], &path, a);
	update_path(&path, &ret, a);
	buf = malloc_gc(&a->gc, 200);
	buf = getcwd(buf, sizeof(char) * 200);
	if (ret == -1 && ft_strcmp(path, "-"))
	{
		ft_no_such_file(a, "cd");
		return (1);
	}
	env = ft_keyshr(a->env, "PWD");
	if (env)
		env->content = buf;
	return (ret);
}

int	ft_pwd(t_all *a, char **args)
{
	char	*buf;
	t_env	*env;

	(void)args;
	buf = malloc_gc(&a->gc, sizeof(char) * 200);
	buf = getcwd(buf, 200);
	if (!buf)
	{
		env = ft_keyshr(a->env, "PWD");
		if (env)
			ft_printf(1, "%s\n", env->content);
	}
	else
		ft_printf(1, "%s\n", buf);
	return (0);
}
