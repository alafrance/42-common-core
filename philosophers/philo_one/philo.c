/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:58:35 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/30 17:44:44 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*life_philo(void	*args)
{
	t_arg	*arg;

	arg = args;
	while (1 && !arg->philo->err)
	{
		if (arg->info->nb_meal_to_be_sated != -1
			&& arg->info->nb_meal_to_be_sated == arg->philo->nb_eat)
			break ;
		if (philo_eat(arg->philo, arg->info, arg->index))
			arg->philo->err = 1;
		if (!arg->philo->err && philo_sleep(arg->info, arg->index))
			arg->philo->err = 1;
		if (!arg->philo->err)
			print_philo(arg->index, "is thinking",
				arg->info, get_time(arg->info->time_start));
	}
	return (NULL);
}

int	philo_sleep(t_info *info, int index)
{
	if (print_philo(index, "is sleeping", info, get_time(info->time_start)))
		return (1);
	usleep(info->time_to_sleep * 1000);
	return (0);
}

int	take_fork(t_info *info, int index, int index_fork)
{
	if (lock_mutex(&info->fork[index_fork], &info->print))
		return (1);
	if (print_philo(index, "has taken a fork", info,
			get_time(info->time_start)))
		return (1);
	return (0);
}

int	philo_eat(t_philo *philo, t_info *info, int index)
{
	struct timeval	buf;

	if (take_fork(info, index, index - 1))
		return (1);
	if (take_fork(info, index, index % info->number_philo))
		return (1);
	if (gettimeofday(&buf, NULL) == -1)
		return (1);
	if (lock_mutex(&philo->mutex_last_time_eat, &info->print))
		return (1);
	philo->last_time_eat = buf.tv_sec * 1000 + buf.tv_usec / 1000;
	philo->nb_eat += 1;
	if (unlock_mutex(&philo->mutex_last_time_eat, &info->print))
		return (1);
	if (print_philo(index, "is eating", info, get_time(info->time_start)))
		return (1);
	usleep(info->time_to_eat * 1000);
	if (unlock_mutex(&info->fork[index % info->number_philo], &info->print))
		return (1);
	if (unlock_mutex(&info->fork[index - 1], &info->print))
		return (1);
	return (0);
}

time_t	get_time(time_t time_start)
{
	time_t			elapsed_time;
	struct timeval	tv_now;

	if (gettimeofday(&tv_now, NULL) == -1)
		return (-1);
	elapsed_time = tv_now.tv_sec * 1000 + tv_now.tv_usec / 1000;
	elapsed_time -= time_start;
	return (elapsed_time);
}
