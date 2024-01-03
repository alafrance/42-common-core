/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   union.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/22 18:11:50 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/22 20:22:00 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_union(char *s1, char *s2)
{
	int i;
	int ascii[128];
	i = 0;
	while (ascii[i])
		ascii[i++] = 0;
	i = 0;
	while (s1[i])
	{
		if (s1[i] < 48 && ascii[s1[i] - 0] == 0)
		{
			ft_putchar(s1[i]);
			ascii[s1[i] - 0] = 1;
		}
		if (s1[i] >= 48	&& ascii[s1[i] - 48] == 0)
		{
			ft_putchar(s1[i]);
			ascii[s1[i] - 48] = 1;
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (s2[i] < 48 && ascii[s2[i] - 0] == 0)
		{
			ft_putchar(s2[i]);
			ascii[s2[i] - 0] = 1;
		}
		if (s2[i] >= 48	&& ascii[s2[i] - 48] == 0)
		{
			ft_putchar(s2[i]);
			ascii[s2[i] - 48] = 1;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_union(av[1], av[2]);
	}
	write(1, "\n", 1);
	return (0);	
}
