/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/18 23:09:45 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/18 23:18:33 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int		main(int argc, char **argv)
{
	int			number;
	char		*dict;
	int			error;

	error = 0;
	if (argc != 2 && argc != 3)
		error = 1;
	if (argc == 3)
	{
		dict = argv[1];
		number = ft_check_number(argv[2]);
		if (number < 0)
			error = 1;
		if (ft_dictionnaire(argv[1]) == NULL)
			error = 1;
		dict = ft_space(ft_dictionnaire(argv[1]));
	}
	if (error == 1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}
