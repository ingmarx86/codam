/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 09:54:09 by inoteboo          #+#    #+#             */
/*   Updated: 2023/08/29 10:05:26 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_stamp(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	dead_philo_checker(void *arg)
{
	struct s_philo	*strct;

	strct = (struct s_philo *) arg;
	while (strct->end_check + 1 < strct->num_philos)
	{
		if (strct->philo_id == 1)
			strct->end_check = 0;
		pthread_mutex_lock(&strct[strct->philo_id].time_meals_lock);
		if (strct[strct->philo_id].meals == 0)
			strct->end_check++;
		if (((time_stamp() - strct->time_to_die) > strct[strct->philo_id]
				.eat_timestamp) && strct[strct->philo_id].meals != 0)
		{
			philo_died(arg);
			return ;
		}
		pthread_mutex_unlock(&strct[strct->philo_id].time_meals_lock);
		strct->philo_id++;
		if (strct->philo_id == strct->num_philos)
			strct->philo_id = 1;
		usleep(500);
	}
}

void	eat_sleep_think(void *ptr)
{
	struct s_philo	*strct;
	int				right_fork;

	strct = (struct s_philo *) ptr;
	right_fork = 1;
	if (strct->philo_id == strct->num_philos)
		right_fork = 1 - strct->philo_id;
	printf("%ld %d is thinking\n", time_stamp(), strct->philo_id);
	pthread_mutex_lock(&strct[0].fork);
	printf("%ld %d has taken a fork\n", time_stamp(), strct->philo_id);
	pthread_mutex_lock(&strct[right_fork].fork);
	printf("%ld %d has taken a fork\n", time_stamp(), strct->philo_id);
	pthread_mutex_lock(&strct->time_meals_lock);
	strct->eat_timestamp = time_stamp();
	printf("%ld %d is eating\n", strct->eat_timestamp, strct->philo_id);
	pthread_mutex_unlock(&strct->time_meals_lock);
	usleep(strct->time_eating * 1000);
	pthread_mutex_unlock(&strct[0].fork);
	pthread_mutex_unlock(&strct[right_fork].fork);
	pthread_mutex_lock(&strct->time_meals_lock);
	strct->meals--;
	pthread_mutex_unlock(&strct->time_meals_lock);
	printf("%ld %d is sleeping\n", time_stamp(), strct->philo_id);
	usleep(strct->time_sleeping * 1000);
}

void	philosopher(void *arg)
{
	struct s_philo	*strct;
	int				id;
	int				meals;
	int				dead;

	strct = (struct s_philo *) arg;
	id = strct->philo_id;
	meals = 1;
	dead = 0;
	if ((id % 2) == 0)
		usleep(strct->time_eating * 500);
	while ((meals > 0 || strct->all_the_meals == 1) && dead == 0)
	{
		eat_sleep_think(arg);
		pthread_mutex_lock(&strct->time_meals_lock);
		meals = strct->meals;
		pthread_mutex_unlock(&strct->time_meals_lock);
		pthread_mutex_lock(&strct[0 - id].dead_lock);
		dead = strct[0 - id].dead;
		pthread_mutex_unlock(&strct[0 - id].dead_lock);
	}
}

int	main(int argc, char *argv[])
{
	int				exit_code;
	struct s_philo	*strct;

	exit_code = input_validator(argc, argv);
	strct = struct_filler(argv, exit_code);
	if (strct == NULL)
		exit_code = 1;
	if (exit_code == 0)
	{
		exit_code += mutex_creator(strct);
		exit_code += thread_creator(strct);
		exit_code += destroyer_of_all(strct);
	}
	if (strct != NULL)
		free (strct);
	return (exit_code);
}

// system("leaks philo");