/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rev_params.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/13 22:34:29 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/15 09:56:13 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int i;
	int o;

	o = argc - 1;
	i = 0;
	while (o != 0)
	{
		while (argv[o][i] != '\0')
		{
			ft_putchar(argv[o][i]);
			i++;
		}
		i = 0;
		ft_putchar('\n');
		o--;
	}
}
