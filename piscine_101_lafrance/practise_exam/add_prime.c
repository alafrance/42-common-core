/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   add_prime.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/22 21:18:34 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/22 22:09:26 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

int ft_is_prime(int a) 
{
	long count;
	long longnb;

	longnb = a;
	count = 2;
	if (longnb <= 1)
		return (0);
	if (longnb == 2)
		return (1);
	while (count * count <= longnb)
	{
		if (longnb % count != 0)
			count++;
		else
			return (0);
	}
	return (1);
}

int ft_sum(int a)
{
	int i;
	int sum;

	sum = 0;
	i = 0;
	while (i <= a)
	{
		if (ft_is_prime(i) == 1)
		{
			sum += i;		
		}
		i++;
	}
	return (sum);
}

int ft_atoi(char *str)
{
	int i;
	int atoi;

	atoi = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoi = (atoi * 10) + (str[i] - 48);
		i++;
	}
	return (atoi);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putnbr(int b)
{
	unsigned int nbr;

	nbr = b;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);	
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int a;
		int b;

		a = ft_atoi(av[1]);
		if (a < 0)
		{
			write(1, "0", 1);
			return (1);
		}
		b = ft_sum(a);
		ft_putnbr(b);
		write(1, "\n", 1);
		return (0);	
	}
	write(1, "0", 1);
	return(1);
}
