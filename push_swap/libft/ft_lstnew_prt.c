/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_prt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:24:33 by alafranc          #+#    #+#             */
/*   Updated: 2021/03/24 14:46:03 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstnew_prt(t_list **s, size_t count, size_t size)
{
	if (count < 0 || size < 0)
		return (0);
	*s = malloc(count * size);
	if (!s)
		return (0);
	return (1);
}
