/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:16:03 by alafranc          #+#    #+#             */
/*   Updated: 2021/03/24 13:35:07 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size_nb(unsigned long long nb, int base)
{
	int	count;

	count = 1;
	while (nb >= (unsigned long long)base)
	{
		nb /= base;
		count++;
	}
	return (count);
}
