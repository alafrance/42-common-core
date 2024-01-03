/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_and_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:22:00 by qurobert          #+#    #+#             */
/*   Updated: 2021/06/24 16:05:07 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_chevron(char *line, int *i, int quote, int count)
{
	while (line[*i] == '<' && !quote)
	{
		count++;
		(*i)++;
		if (count > 2)
			return (1);
	}
	return (0);
}

char	*ft_strjoin_ws(char *s1, char *s2, t_all *a)
{
	int		i;
	int		j;
	char	*buf;

	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (s1);
	buf = malloc_gc(&a->gc, sizeof(char) * (ft_strlen(s1) + \
	ft_strlen(s2) + 2));
	if (!buf)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		buf[i++] = s1[j++];
	j = 0;
	buf[i++] = ' ';
	while (s2[j])
		buf[i++] = s2[j++];
	buf[i] = '\0';
	return (buf);
}

int	ft_re_size(char *line, int *i, int (*f)(char c, char *str), char *del)
{
	int	size;

	size = 0;
	if (f(line[*i], del) && line[*i - 1] && line[*i - 1] == ' ')
		size++;
	if (line[*i] == '>' && line[*i - 1] && ft_isdigit(line[*i - 1]))
	{
		(*i)--;
		size++;
		if (line[*i] && line[*i - 1] && ft_isdigit(line[*i - 1]))
		{
			(*i)++;
			size--;
		}
		if (line[*i] && line[*i] == ' ')
			size++;
	}
	return (size);
}

void	ft_set_ini(int *start, int *size, int beg, int end)
{
	*start = beg;
	*size = end - beg;
}

int	ft_check_name(int *pos, int *end, int *count, char *line)
{
	int	plus;

	plus = 0;
	while ((*end) > -1 && line[(*end)] && line[(*end)] != ' ' && \
	((line[(*end)] == '>' && !ft_is_bs_before(line, (*end))) || \
	(ft_isdigit(line[(*end)]) && (*count) < 2 && ((*end) == 0 || \
	((*end) > 0 && line[(*end) - 1] == ' ')))))
	{
		if (ft_isdigit(line[(*end)]))
		{
			if (count == 0)
				*pos = (*end);
			(*count)++;
		}
		plus = 1;
		(*end)--;
	}
	return (plus);
}
