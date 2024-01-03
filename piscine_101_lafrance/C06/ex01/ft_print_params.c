/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_params.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/10 11:17:18 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/15 09:54:31 by alafranc    ###    #+. /#+    ###.fr     */
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

	o = 1;
	i = 0;
	while (o != argc)
	{
		while (argv[o][i] != '\0')
		{
			ft_putchar(argv[o][i]);
			i++;
		}
		i = 0;
		ft_putchar('\n');
		o++;
	}
}
