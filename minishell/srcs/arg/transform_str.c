/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:27:50 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/24 16:27:08 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*transform_home(t_all *a, char *new_str, int *i)
{
	t_env	*str_env;

	(*i)++;
	str_env = ft_keyshr(a->env, "HOME");
	if (str_env && str_env->content)
	{
		new_str = ft_strjoin(new_str, str_env->content);
		ft_lstadd_front(&a->gc, ft_lstnew(new_str));
	}
	return (new_str);
}

char	*transform_var_env(char *arg, t_all *a, char *new_str, int *i)
{
	t_env	*str_env;

	(*i)++;
	str_env = find_env(a, arg, i);
	if (str_env && str_env->content)
	{
		new_str = ft_strjoin(new_str, str_env->content);
		ft_lstadd_front(&a->gc, ft_lstnew(new_str));
	}
	return (new_str);
}

char	*ft_add_char(char *arg, t_all *a, int *i, char *new_str)
{
	char	buf[2];

	buf[0] = arg[*i];
	buf[1] = '\0';
	new_str = ft_strjoin(new_str, buf);
	ft_lstadd_front(&a->gc, ft_lstnew(new_str));
	(*i)++;
	return (new_str);
}

char	*transform_arg_with_env(char *arg, t_all *a)
{
	int		i;
	char	quote;
	char	*new_str;

	i = 0;
	quote = 0;
	new_str = NULL;
	while (arg[i])
	{
		if ((is_quote_or_d_quote(arg, i)) && quote == 0)
			quote = arg[i];
		else if (arg[i] == quote)
			quote = 0;
		if (ft_is_backslash_before(arg, i, '~'))
			new_str = transform_home(a, new_str, &i);
		else if (ft_is_backslash_before(arg, i, '$') && quote != '\'' && \
				arg[i + 1] && !ft_ccmp(arg[i + 1], "= $\'\""))
			new_str = transform_var_env(arg, a, new_str, &i);
		else
			new_str = ft_add_char(arg, a, &i, new_str);
	}
	return (new_str);
}
