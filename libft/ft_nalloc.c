/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nalloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:25:35 by alafranc          #+#    #+#             */
/*   Updated: 2021/03/24 16:04:03 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nalloc(char **s, size_t count, size_t size)
{
	if (count < 0 || size < 0)
		return (0);
	*s = malloc(count * size);
	if (!s)
		return (0);
	return (1);
}

int	ft_nalloc_void(void **s, size_t count, size_t size)
{
	if (count < 0 || size < 0)
		return (0);
	*s = malloc(count * size);
	if (!s)
		return (0);
	return (1);
}

int	ft_nalloc_list(t_list **s, size_t count, size_t size)
{
	if (count < 0 || size < 0)
		return (0);
	*s = malloc(count * size);
	if (!s)
		return (0);
	return (1);
}
