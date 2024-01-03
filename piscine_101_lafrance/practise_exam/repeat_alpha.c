/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   repeat_alpha.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/22 14:38:08 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/22 15:24:11 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


int compteur(char i)
{
	int count = 0;
	if (i >= 97 && i <= 122)
	{
		count = i - 97 + 1;
		return (count);
	}
	if (i >= 65 && i <= 90)
	{
		count = i - 65 + 1;
		return(count);
	}
	else
		return (1);
}
void repeat_alpha(char *str)
{
	int i;
	int a;
	
	a = 0;
	i = 0;
	while (str[i])
	{
		a = compteur(str[i]);
		while (a-- != 0) 
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		repeat_alpha(av[1]);
	}
	write(1, "\n", 1);
	return (0);

}
