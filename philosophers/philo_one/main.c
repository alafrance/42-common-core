/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:29:31 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/30 17:53:25 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	is_all_sated(t_philo *philo, t_info *info)
{
	int	i;

	i = -1;
	(void)philo;
	if (info->nb_meal_to_be_sated == -1)
		return (0);
	while (++i != info->number_philo)
	{
		if (philo[i].nb_eat != info->nb_meal_to_be_sated)
			return (0);
	}
	return (1);
}

int	ft_is_dead(t_philo philo, t_info *info, int i)
{
	struct timeval	buf;
	time_t			now;

	if (gettimeofday(&buf, NULL) == -1)
		return (1);
	now = buf.tv_sec * 1000 + buf.tv_usec / 1000;
	if ((!philo.last_time_eat
			&& (get_time(info->time_start) > info->time_to_die))
		|| (philo.last_time_eat
			&& (now - philo.last_time_eat > info->time_to_die)))
	{
		print_philo(i + 1, "is died", info, get_time(info->time_start));
		return (1);
	}
	return (0);
}

void	wait_thread_and_mutex_end(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (1)
	{
		if (is_all_sated(philo, info))
			break ;
		if (lock_mutex(&philo[i].mutex_last_time_eat, &info->print))
			break ;
		if (ft_is_dead(philo[i], info, i))
			break ;
		if (unlock_mutex(&philo[i].mutex_last_time_eat, &info->print))
			break ;
		if (i + 1 == info->number_philo)
			i = -1;
		i++;
		usleep(2000);
	}
	i = -1;
	pthread_mutex_lock(&info->print);
	while (++i != info->number_philo)
		pthread_detach(philo->philosopher);
	i = -1;
	while (++i != info->number_philo)
		pthread_mutex_destroy(&info->fork[i]);
}

int	main(int ac, char **av)
{
	t_info			*info;
	t_philo			*philo;
	void			**gc;
	struct timeval	tv_start;

	if (gettimeofday(&tv_start, NULL) == -1)
		return (1);
	if (ac < 5 || ac > 7)
		return (ft_error_int("Miss / More arguments"));
	if (init_info(ac, av, &info))
		return (free_struct(info, NULL, NULL));
	gc = malloc(sizeof(void *) * info->number_philo);
	info->time_start = tv_start.tv_sec * 1000 + tv_start.tv_usec / 1000;
	philo = init_philo(info, gc);
	if (!philo)
		return (free_struct(info, philo, gc));
	wait_thread_and_mutex_end(philo, info);
	free_struct(info, philo, gc);
	return (0);
}
