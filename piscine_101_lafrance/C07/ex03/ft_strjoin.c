/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/15 20:05:15 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 18:05:50 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strslen(char **strs, int size)
{
	int i;
	int j;
	int res;

	res = 0;
	j = 0;
	i = 0;
	while (i <= size)
	{
		while (strs[i][j])
		{
			j++;
			res++;
		}
		j = 0;
		i++;
	}
	return (res);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	remplissage(int size, char **strs, char *sep, char *str)
{
	int i;
	int j;
	int k;

	i = -1;
	j = 0;
	k = 0;
	while (++i < size)
	{
		while (strs[i][j])
		{
			str[k] = strs[i][j];
			j++;
			k++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			str[k] = sep[j];
			j++;
			k++;
		}
		j = 0;
	}
	str[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *str;

	if (!(str = malloc(sizeof(char) * ((ft_strslen(strs, size) + 1)
				+ ft_strlen(sep) * (size - 1)))))
		return (0);
	remplissage(size, strs, sep, str);
	return (str);
}
