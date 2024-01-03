/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buf_open.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/21 15:41:27 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 20:58:23 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"
#define BUF_SIZE 2000
char *ft_open(void)
{
	int fd;
	int ret;
	char *buf;
	char *c;

	c = NULL;
	if(!(buf = malloc(sizeof(char) * BUF_SIZE)))
		return (c);
	fd = open("../plateaux/plateau", O_RDONLY);
	ret = 0;
	if (fd == -1)
		return (c);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	printf("%s", buf);
	if (close(fd) == -1)
		return (c);
	return (buf);
}

struct s_information *ft_open_to_struct(char *buf)
{
	t_information *tab;
	int i;

	i = 0;
	while (buf[i] != '\n')
	{
		while (buf[i] >= '0' && buf[i] <= '9')
		{
			tab[i].hauteur = buf[i];
			i++;
		}
		tab[i].emptycase = buf[i];
		i++;
		tab[i].obstacle = buf[i];
		i++;
		tab[i].fill = buf[i];
		i++;
	}
	while (buf[i] != '\n')
		i++;
	tab[i].largeur = i;
	tab[i].end = 0;
	return (tab);
}
void				ft_putchar(char c)
{
	write(1, &c, 1);
}

void				ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void				ft_putnbr(int n)
{
	unsigned int nbr;

	if (n < 0)
	{
		ft_putchar('-');
		nbr = n * -1;
	}
	else
		nbr = n;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}

void				ft_show_tab(struct s_information *tab)
{
	int i;

	i = 0;
	while (tab[i].end != 0)
	{
		ft_putnbr(tab[i].hauteur);
		write(1, "\n", 1);
		ft_putnbr(tab[i].largeur);
		write(1, "\n", 1);
		i++;
	}
}
