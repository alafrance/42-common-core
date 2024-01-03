/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:50:03 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/30 17:52:42 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_info	*pick_information(int ac, char **av)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->number_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->is_somebody_die = 0;
	info->fork = NULL;
	if (ac == 6)
		info->nb_meal_to_be_sated = ft_atoi(av[5]);
	else
		info->nb_meal_to_be_sated = -1;
	return (info);
}

int	init_info(int ac, char **av, t_info **info)
{
	*info = pick_information(ac, av);
	if (!(*info))
		return (ft_error_int("Malloc"));
	if (info_error(*info, ac, av))
		return (ft_error_int(info_error(*info, ac, av)));
	(*info)->fork = init_fork((*info)->number_philo);
	if (!(*info)->fork)
		return (1);
	if (pthread_mutex_init(&(*info)->print, NULL))
		return (ft_error_int("Mutex init failed"));
	return (0);
}

pthread_mutex_t	*init_fork(int number_of_philo)
{
	pthread_mutex_t	*fork;
	int				i;

	i = 0;
	fork = malloc(sizeof(pthread_mutex_t) * (number_of_philo));
	if (!fork)
		return (ft_error("Malloc"));
	while (i < number_of_philo)
	{
		if (pthread_mutex_init(&fork[i], NULL))
			return (ft_error("Mutex init failed"));
		i++;
	}
	return (fork);
}

t_philo	init_philo_assignement(t_philo philo)
{
	philo.is_eaten = 0;
	philo.err = 0;
	philo.last_time_eat = 0;
	philo.nb_eat = 0;
	if (pthread_mutex_init(&philo.mutex_last_time_eat, NULL))
		return (philo);
	return (philo);
}

t_philo	*init_philo(t_info *info, void **gc)
{
	t_philo		*philo;
	t_arg		*arg;
	int			i;

	i = -1;
	philo = malloc(sizeof(t_philo) * (info->number_philo));
	if (!philo)
		return (ft_error("Malloc"));
	while (++i != info->number_philo)
	{
		philo[i] = init_philo_assignement(philo[i]);
		arg = malloc(sizeof(t_arg));
		if (!arg)
			return (ft_error("Malloc"));
		arg->philo = &philo[i];
		arg->index = i + 1;
		arg->info = info;
		gc[i] = (void *)arg;
		if (pthread_create(&philo[i].philosopher, NULL, life_philo, arg))
			return (ft_error("Fail creation threads\n"));
		usleep(100);
	}
	return (philo);
}
