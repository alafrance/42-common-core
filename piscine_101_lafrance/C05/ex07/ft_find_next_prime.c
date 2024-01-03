/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_find_next_prime.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alafranc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/13 18:57:38 by alafranc     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/15 16:52:26 by alafranc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	long count;
	long longnb;

	longnb = nb;
	count = 2;
	if (longnb <= 1)
		return (0);
	if (longnb == 2)
		return (0);
	while (count * count <= longnb)
	{
		if (longnb % count != 0)
			count++;
		else
			return (0);
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (ft_is_prime(nb) != 1)
		nb++;
	return (nb);
}
