/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:29:19 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/30 16:23:58 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	lock_mutex(pthread_mutex_t *mutex, pthread_mutex_t *print)
{
	if ((pthread_mutex_lock(mutex)))
	{
		pthread_mutex_lock(print);
		return (ft_error_int("Mutex lock"));
	}
	return (0);
}

int	unlock_mutex(pthread_mutex_t *mutex, pthread_mutex_t *print)
{
	if (pthread_mutex_unlock(mutex))
	{
		pthread_mutex_lock(print);
		return (ft_error_int("Mutex unlock"));
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long	nb;
	int		sign;
	int		i;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i++] - '0';
		if (nb < 0)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
	}
	return ((int)(nb * sign));
}

int	print_philo(int	index, char *msg, t_info *info, time_t time)
{
	(void)msg;
	(void)index;
	if (time == -1)
		return (1);
	if (lock_mutex(&info->print, &info->print))
		return (1);
	printf("%ld %d %s\n", time, index, msg);
	if (unlock_mutex(&info->print, &info->print))
		return (1);
	return (0);
}
