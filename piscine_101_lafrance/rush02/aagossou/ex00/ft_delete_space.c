/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_delete_space.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/18 23:10:15 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/18 23:11:27 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

char	*ft_space(char *buf)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if (!(dest = malloc(sizeof(char) * 30000)))
		return (NULL);
	while (buf[i] != '\0')
	{
		while (buf[i] >= '0' && buf[i] <= '9')
		{
			dest[j] = buf[i];
			j++;
			i++;
		}
		while ((buf[i] >= 9 && buf[i] <= 13) || buf[i] == ' ')
			i++;
		if (buf[i] == ':')
		{
			dest[j] = buf[i];
			j++;
			i++;
		}
		while ((buf[i] >= 9 && buf[i] <= 13) || buf[i] == ' ')
			i++;
		while (buf[i] >= 32 && buf[i] <= 126)
		{
			dest[j] = buf[i];
			i++;
			j++;
		}
		if (buf[i] == '\n')
		{
			dest[j] = buf[i];
			j++;
			i++;
		}
	}
	dest[j] = '\0';
	return (dest);
}
