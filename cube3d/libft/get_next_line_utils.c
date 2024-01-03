/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 00:03:45 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/24 10:33:52 by alafranc         ###   ########lyon.fr   */
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
	if (!(buf = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
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

int		ft_strchr_gnl(char *file, int c)
{
	int i;

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

int		count_end_line(char *s)
{
	int end;

	if (ft_strchr_gnl(s, '\n') == -1)
		end = ft_strlen(s);
	else
		end = ft_strchr_gnl(s, '\n');
	return (end);
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
	end = count_end_line(s);
	if (end == 0)
		return (ft_strdup(""));
	while (i < end && s[i])
		i++;
	if (!(buf = malloc(sizeof(char) * (i + 1))))
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
