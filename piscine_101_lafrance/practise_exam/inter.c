/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   inter.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/22 18:11:53 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/22 20:21:42 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void ft_inter(char *s1, char *s2)
{
	int i;
	int j;
	int k;
	int ascii[128] = {0};
	char str[256] = {0};

	j = 0;
	i = 0;
	k = 0;
	while (s1[i])
	{
		while (s2[j])
		{
			if (s1[i] == s2[j] && ascii[s1[i]] == 0)
			{
				ascii[s1[i]] = 1;
				str[k] = s1[i];
				str[k + 1] = '\0';
				k++;
			}
			j++;
		}	
		j = 0;
		i++;
	}
	k = 0;
	while (str[k])
	{
		write(1, &str[k], 1);
		k++;
	}

}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_inter(av[1], av[2]);
	}
	write(1, "\n", 1);
	return (0);
}
