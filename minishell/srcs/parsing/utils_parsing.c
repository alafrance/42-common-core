/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:59:21 by qurobert          #+#    #+#             */
/*   Updated: 2021/06/24 15:49:56 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_bs_before(char *line, int i)
{
	if (line[i] && (i != 0 && line[i - 1] && line[i - 1] == '\\'))
		return (1);
	return (0);
}

void	ft_skip_whitespace(char *line, int *i)
{
	while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
		(*i)++;
}

void	ft_is_quote(char c, int *quote)
{
	if (!(*quote) && (c == '\'' || c == '\"'))
		*quote = 1;
	else if (*quote && (c == '\'' || c == '\"'))
		*quote = 0;
}

int	ft_delimiter(char c, char *del)
{
	int			i;
	static int	quote;

	i = -1;
	ft_is_quote(c, &quote);
	while (del[++i])
	{
		if (del[i] == c && !quote)
			return (1);
	}
	if (c == '\0')
		return (1);
	return (0);
}

char	*ft_substr_sw(char *s, int w, size_t len)
{
	char	*buf;
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	if (s == NULL)
		return (NULL);
	if (w >= (int)ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	while (size < len && s[w + size])
		size++;
	buf = malloc(sizeof(char) * (size + 1));
	if (!buf)
		return (NULL);
	size = 0;
	while (s[w] && i < len)
	{
		ft_is_quote(s[w], (int *)&size);
		buf[i++] = s[w++];
		if (s[w] && s[w - 1] && s[w - 1] == ' ' && s[w] == ' ' && !size)
			ft_skip_whitespace(s, &w);
	}
	buf[i] = '\0';
	return (buf);
}
