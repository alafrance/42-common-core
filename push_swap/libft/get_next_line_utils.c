/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 00:03:45 by alafranc          #+#    #+#             */
/*   Updated: 2021/04/08 15:38:53 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	buf = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!buf)
		return (NULL);
	while (s1[j])
		buf[i++] = s1[j++];
	j = 0;
	while (s2[j])
		buf[i++] = s2[j++];
	buf[i] = '\0';
	free(s1);
	return (buf);
}

int	ft_strchr_gnl(char *file, int c)
{
	int	i;

	i = 0;
	if (file == NULL)
		return (-1);
	while (file[i])
	{
		if (file[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_substr_end(int *end, char *s)
{
	if (ft_strchr_gnl(s, '\n') == -1)
		*end = ft_strlen(s);
	else
		*end = ft_strchr_gnl(s, '\n');
}

char	*ft_substr_line(char *s)
{
	char	*buf;
	int		size;
	int		i;
	int		end;

	i = 0;
	size = 0;
	if (!s)
		return (NULL);
	ft_substr_end(&end, s);
	if (end == 0)
		return (ft_strdup(""));
	while (i < end && s[i])
		i++;
	buf = malloc(sizeof(char) * (i + 1));
	if (!buf)
		return (NULL);
	i = 0;
	while (s[i] && i < end)
	{
		buf[i] = s[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int	free_error_gnl(char *str_temp)
{
	free(str_temp);
	return (-1);
}
