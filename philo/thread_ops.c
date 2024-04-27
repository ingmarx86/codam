/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:17:25 by inoteboo          #+#    #+#             */
/*   Updated: 2023/08/12 10:18:46 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_creator(void *ptr)
{
	struct s_philo	*strct;
	int				i;

	strct = (struct s_philo *) ptr;
	i = strct[0].num_philos;
	if (pthread_mutex_init(&strct[0].dead_lock, NULL) != 0)
		return (1);
	while (i >= 0)
	{
		strct[i].eat_timestamp = time_stamp();
		if (pthread_mutex_init(&strct[i].fork, NULL) != 0)
			return (1);
		if (pthread_mutex_init(&strct[i].time_meals_lock, NULL) != 0)
			return (1);
		i--;
	}
	return (0);
}

int	thread_creator(void *ptr)
{
	struct s_philo	*strct;
	int				i;

	strct = (struct s_philo *) ptr;
	i = 0;
	if (pthread_create(&strct[i].thread,
			NULL, (void *)dead_philo_checker, strct) != 0)
		return (1);
	i++;
	while (i <= strct[i].num_philos)
	{
		strct[i].philo_id = i;
		if (pthread_create(&strct[i].thread,
				NULL, (void *)philosopher, strct + i) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	destroyer_of_all(void *ptr)
{
	struct s_philo	*strct;
	int				i;

	strct = (struct s_philo *) ptr;
	i = 0;
	while (i <= strct->num_philos)
	{
		if (pthread_join(strct[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i <= strct->num_philos)
	{
		if (pthread_mutex_destroy(&strct[i].fork) != 0)
			return (1);
		i++;
	}
	return (0);
}

void	philo_died(void *arg)
{
	struct s_philo	*strct;

	strct = (struct s_philo *) arg;
	pthread_mutex_unlock(&strct[strct->philo_id].time_meals_lock);
	printf("%ld %d died\n", time_stamp(), strct->philo_id);
	pthread_mutex_lock(&strct->dead_lock);
	strct->dead = 1;
	pthread_mutex_unlock(&strct->dead_lock);
	return ;
}
