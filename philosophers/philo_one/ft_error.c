/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:30:03 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/30 16:23:13 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

char	*info_error(t_info *info, int ac, char **av)
{
	if (info->number_philo <= 0)
		return ("negative or zero number of philo");
	if (info->time_to_die < 0)
		return ("negative time to die");
	if (info->time_to_eat < 0)
		return ("negative time to eat");
	if (info->time_to_sleep < 0)
		return ("negative time to sleep");
	if (ac == 6 && info->nb_meal_to_be_sated < 0)
		return ("negative Time (each philo must eat)");
	if (!ft_is_digit(av[1])
		|| !ft_is_digit(av[2])
		|| !ft_is_digit(av[3])
		|| !ft_is_digit(av[4])
		|| (ac == 6 && !ft_is_digit(av[5])))
		return ("not only numbers");
	return (NULL);
}

int	ft_error_int(char *error_msg)
{
	printf("Error: %s\n", error_msg);
	return (1);
}

void	*ft_error(char *error_msg)
{
	printf("Error: %s\n", error_msg);
	return (NULL);
}

int	free_struct(t_info *info, t_philo *philo, void **gc)
{
	int	i;

	i = -1;
	if (gc)
	{
		while (++i != info->number_philo)
			free(gc[i]);
		free(gc);
	}
	if (info->fork)
		free(info->fork);
	if (info)
		free(info);
	if (philo)
		free(philo);
	return (1);
}
