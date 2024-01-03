/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wdmatch.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/22 16:03:16 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/22 20:21:55 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
char *wdmatch(char *s1, char *s2)
{
	int i = 0;
	int taille = 0;
	int count = 0;
	int o = 0;
	while (s1[i])
	{
		taille++;
		i++;
	}
	i = 0;
	while (i <= taille && s2[o])
	{
		if (s1[i] == s2[o])
		{
			count++;
			i++;
			o++;
		}
		else
		{
			o++;
		}
	}
	if (taille == count)
		return(s1);
	else
		return (NULL);
}

int main(int ac, char **av)
{
	char *tab;
	
	tab = wdmatch(av[1], av[2]);
	ft_putstr(tab);
	write(1, "\n", 1);
	return (0);
}
