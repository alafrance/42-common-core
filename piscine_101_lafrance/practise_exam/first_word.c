/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   first_word.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/22 11:12:39 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/22 14:44:45 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		while (*av[1] == '\0' || (*av[1] == ' ' || *av[1] == '\t'))
			++av[1];
		while (*av[1] != '\0' && (*av[1] != ' ' && *av[1] != '\t'))
			write(1, av[1]++, 1);	
	}
	write(1, "\n", 1);
	return (0);
}
