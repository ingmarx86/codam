/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:29:04 by inoteboo          #+#    #+#             */
/*   Updated: 2023/08/12 15:09:20 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	x;
	char	*ptr;

	x = count * size;
	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (0);
	while ((x) > 0)
	{
		ptr[i] = '\0';
		i++;
		x--;
	}
	return ((void *)ptr);
}

int	philo_atoi(const char *str)
{
	long long int	c;

	c = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (!((*str >= 48 && *str <= 57)))
		return (-1);
	while (*str >= 48 && *str <= 57)
	{
		c = (c * 10) + (*str - 48);
		str++;
	}
	if (*str != '\0')
		return (-1);
	if (c > 2147483647)
		return (-1);
	return (c);
}

void	*struct_filler(char *argv[], int exit_code)
{
	struct s_philo	*strct;
	int				i;

	i = 0;
	if (exit_code == 1)
		return (NULL);
	strct = NULL;
	strct = ft_calloc(philo_atoi(argv[1]) + 2, sizeof(struct s_philo));
	while (i <= philo_atoi(argv[1]))
	{
		strct[i].num_philos = philo_atoi(argv[1]);
		strct[i].time_to_die = philo_atoi(argv[2]);
		strct[i].time_eating = philo_atoi(argv[3]);
		strct[i].time_sleeping = philo_atoi(argv[4]);
		strct[i].meals = -1;
		if (argv[5] != NULL)
			strct[i].meals = philo_atoi(argv[5]);
		else
			strct[i].all_the_meals = 1;
		strct[i].dead = 0;
		strct[i].philo_id = i;
		i++;
	}
	strct[0].philo_id = 1;
	return (strct);
}

int	input_validator(int argc, char *argv[])
{
	if ((argc != 5 && argc != 6))
	{
		error_message_printer();
		return (1);
	}
	if ((philo_atoi(argv[1]) < 0) || (philo_atoi(argv[2]) < 0)
		|| (philo_atoi(argv[3]) < 0) || (philo_atoi(argv[4]) < 0)
		|| (argc == 6 && (philo_atoi(argv[5]) < 0)))
	{
		error_message_printer();
		return (1);
	}
	if (philo_atoi(argv[1]) == 1)
	{
		printf("\n\nA philosopher can't eat with one fork\n\n");
		return (1);
	}
	if (philo_atoi(argv[1]) > 500)
	{
		printf("\n\nThats a bit much..\n\n");
		return (1);
	}
	return (0);
}

void	error_message_printer(void)
{
	printf("\nYou're doing it wrong!\n\n");
	printf("Please input 4 or 5 positive numbers\n");
	printf("Maximum allowed value is 2147483647\n");
	printf("1st for the number of philosophers (max 500)\n");
	printf("2nd for 'time to die'\n");
	printf("3rd for 'time to eat'\n");
	printf("4th for 'time to sleep'\n");
	printf("5th is for the number of meals and is optional\n");
	printf("If the number of meals is not specified,");
	printf(" the simulation will run until a philosopher dies\n\n");
	printf("Example: ./philo 5 35 10 10 5\n\n");
}
