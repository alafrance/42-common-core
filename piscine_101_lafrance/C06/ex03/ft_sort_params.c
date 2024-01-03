/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_params.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/13 22:52:00 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/15 12:23:59 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strcmp(int i, char **argv)
{
	int j;

	j = 0;
	while (argv[i][j] || argv[i][j])
	{
		if (argv[i][j] != argv[i + 1][j])
		{
			return (argv[i][j] - argv[i + 1][j]);
		}
		j++;
	}
	return (0);
}

void	ft_tri(int argc, char **argv)
{
	int		i;
	int		j;
	char	*swap;

	j = 0;
	i = 0;
	while (j < argc)
	{
		i = 0;
		while (i < argc - 1)
		{
			if (ft_strcmp(i, argv) > 0)
			{
				swap = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = swap;
			}
			i++;
		}
		j++;
	}
}

int		main(int argc, char **argv)
{
	int i;
	int o;

	i = 0;
	o = 1;
	ft_tri(argc, argv);
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
	return (0);
}
