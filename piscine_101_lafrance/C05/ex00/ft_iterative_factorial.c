/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_iterative_factorial.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/11 15:44:19 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/14 19:54:47 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

int		ft_iterative_factorial(int nb)
{
	int i;
	int o;

	i = nb;
	o = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (i != 0)
	{
		o *= i;
		i--;
	}
	nb = o;
	return (nb);
}
