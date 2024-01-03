/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_is_prime.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/13 14:07:24 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/15 12:00:17 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long count;
	long longnb;

	longnb = nb;
	count = 2;
	if (longnb <= 1)
		return (0);
	if (longnb == 2)
		return (1);
	while (count * count <= longnb)
	{
		if (longnb % count != 0)
			count++;
		else
			return (0);
	}
	return (1);
}
