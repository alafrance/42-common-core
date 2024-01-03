/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:29:37 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/30 16:37:24 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_info
{
	int				number_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meal_to_be_sated;
	int				is_somebody_die;
	time_t			time_start;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}				t_info;

typedef struct s_philo
{
	pthread_t		philosopher;
	int				err;
	int				is_eaten;
	pthread_mutex_t	mutex_last_time_eat;
	time_t			last_time_eat;
	int				nb_eat;
}				t_philo;

typedef struct s_arg
{
	t_philo	*philo;
	int		index;
	t_info	*info;
}				t_arg;

/*
**		FT_ERROR
*/
void			*ft_error(char *error_msg);
int				ft_error_int(char *error_msg);
char			*info_error(t_info *info, int ac, char **av);
int				free_struct(t_info *info, t_philo *philo, void **gc);
/*
**		FT_UTILITY
*/
int				ft_atoi(const char *str);
int				print_philo(int	index, char *msg, t_info *info,
					time_t last_time_eat);
int				ft_is_digit(char *str);
time_t			get_time(time_t time_start);
int				lock_mutex(pthread_mutex_t *mutex, pthread_mutex_t *print);
int				unlock_mutex(pthread_mutex_t *mutex, pthread_mutex_t *print);
/*
**		INIT_STRUCT
*/
t_info			*pick_information(int ac, char **av);
int				init_info(int ac, char **av, t_info **info);
pthread_mutex_t	*init_fork(int number_of_philo);
t_philo			*init_philo(t_info *info, void **gc);
/*
**		PHILO MAIN
*/
void			*life_philo(void *arg);
int				philo_eat(t_philo *philo, t_info *info, int index);
int				philo_is_die(t_philo *philo, time_t *elapsed_time);
void			wait_thread_and_mutex_end(t_philo *philo, t_info *info);
int				philo_sleep(t_info *info, int index);
#endif