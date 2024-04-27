/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:14:24 by inoteboo          #+#    #+#             */
/*   Updated: 2023/08/12 14:03:33 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <stdarg.h>
# include <pthread.h>
# include <sys/time.h>

int		philo_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
long	time_stamp(void);
void	dead_philo_checker(void *arg);
void	philo_died(void *arg);
void	philosopher(void *arg);
void	eat_sleep_think(void *ptr);
void	*struct_filler(char *argv[], int exit_code);
int		mutex_creator(void *ptr);
int		thread_creator(void *ptr);
int		destroyer_of_all(void *ptr);
int		input_validator(int argc, char *argv[]);
void	error_message_printer(void);

struct s_philo
{
	int				end_check;
	int				dead;
	int				num_philos;
	int				philo_id;
	int				meals;
	int				all_the_meals;
	int				time_sleeping;
	int				time_eating;
	int				time_to_die;
	int				time_thinking;
	long			eat_timestamp;
	pthread_mutex_t	fork;
	pthread_mutex_t	time_meals_lock;
	pthread_mutex_t	dead_lock;
	pthread_t		thread;
};

#endif
