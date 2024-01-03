/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   atoi.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/22 15:37:51 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/22 22:20:22 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <xlocale.h>
#include <stdio.h>

int ft_atoi(char *str)
{
	int i;
	int atoi;
	int signe;
	int cpt;

	signe = 1;
	atoi = 0;
	i = 0;
	cpt = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v') && str[i] != '\0')
		i++;
	while (((str[i] == '-') || (str[i] == '+')) && (cpt <= 1))
	{
		if (str[i] == '-')
		{
			signe = -1;
		}
		i++;
		cpt++;
	}
	if (cpt > 1)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoi = atoi * 10 + (str[i] - 48);
		i++;
	}
	return (atoi * signe);	
}

int main(int ac, char **av)
{
	if (ac == 2)
		{
			printf("%d", ft_atoi(av[1]));
		}
	printf("\n");
	printf("%d", atoi(av[1]));
	return(0);
}
