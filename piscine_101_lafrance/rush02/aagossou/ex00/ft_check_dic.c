/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_dic.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/18 23:10:09 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/18 23:11:21 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

#define BUF_SIZE 30000

int		ft_verif(char *buf)
{
	int i;

	i = 0;
	while (buf[i++] != '\0')
	{
		while (buf[i] != '\n')
		{
			if (!(buf[i++] >= '0' && buf[i] <= '9'))
				return (1);
			while (buf[i] >= '0' && buf[i] <= '9')
				i++;
			while (buf[i] == ' ' || (buf[i] >= 9 && buf[i] <= 13))
				i++;
			if (!(buf[i] == ':'))
				return (1);
			i++;
			while (buf[i] == ' ')
				i++;
			if (!(buf[i] >= 32 && buf[i] <= 126))
				return (1);
			while ((buf[i] >= 32 && buf[i] <= 126))
				i++;
			if (!(buf[i] == '\n'))
				return (1);
		}
	}
	return (0);
}

char	*ft_dictionnaire(char *dict)
{
	int		fd;
	int		ret;
	char	*buf;
	char	*c;

	c = NULL;
	if (!(buf = malloc(sizeof(char) * 1000)))
		return (c);
	fd = open(dict, O_RDONLY);
	ret = 0;
	if (fd == -1)
		return (c);
	ret = read(fd, (buf), BUF_SIZE);
	buf[ret] = '\0';
	if (close(fd) == -1)
		return (c);
	if (ft_verif(buf) == 0)
		return (buf);
	else
		return (c);
	return (buf);
}
