/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_number.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/18 23:09:59 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/18 23:19:39 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

int	ft_check_number(char *str)
{
	int i;
	int dest;

	i = 0;
	dest = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '\t'
				|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
				|| str[i] == '\f' || str[i] == ' '))
			return (-1);
		i++;
	}
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		dest = dest * 10 + (str[i] - '0');
		i++;
	}
	return (dest);
}
