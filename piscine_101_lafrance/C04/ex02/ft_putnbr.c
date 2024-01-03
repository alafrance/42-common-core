/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/09 10:32:54 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/09 12:21:39 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

void  ft_putnbr(int nb)
{
	int nb2;

	nb2 = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 0)
	{
		while (nb > 10)
		{
			nb = nb / 10 + 48;
			ft_putchar(nb);
			ft_putchar(nb % 10 + 48);
		}
		if (nb <= 10)
			ft_putchar(nb % 10); 		
	
	}
}


void	putnbr(int n);

int main()
{
	int n = 425161;
	ft_putnbr(n);

}



void	putnbr(int n)
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
		putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}
