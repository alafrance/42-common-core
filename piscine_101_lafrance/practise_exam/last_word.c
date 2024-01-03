/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   last_word.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/22 11:52:17 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/22 14:30:55 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int main(int ac, char **av)
{
	if (ac ==  2)
	{
		int i;

		i = ft_strlen(av[1]);
		while (*av[1] != '\0')
			av[1]++;
		av[1]--;
		while (*av[1] == ' ' || *av[1] == '\t')
			av[1]--;
		while ((*av[1] > 32 && *av[1] <= 126 ))
			av[1]--;
		av[1]++;
		while ((*av[1] > 32 && *av[1] <= 126))
			write(1, av[1]++, 1);
	}
	write (1, "\n", 1);
	return (0);

}
