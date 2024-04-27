/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 08:08:25 by inoteboo          #+#    #+#             */
/*   Updated: 2023/05/21 13:19:12 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_free_to_send = 1;

int	ft_atoi(const char *str)
{
	int				i;
	long long int	c;

	i = 0;
	c = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
	str++;
	if (!((*str >= 48 && *str <= 57) || *str == '-' || *str == '+'))
		return (0);
	if (*str == '-' || *str == '+')
	{
		i = *str;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		c = (c * 10) + (*str - 48);
		str++;
	}
	if (i == 45)
		c = -c;
	return (c);
}

void	flow_control(int sig)
{
	if (sig == SIGUSR1)
		g_free_to_send = 2;
}

void	bit_shooter(char ascii, int count, int pid)
{
	int	time_out;
	
	time_out = 0;
	if (count > 0)
		bit_shooter(ascii / 2, count - 1, pid);
	g_free_to_send = 1;
	if ((ascii % 2) == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	while (g_free_to_send == 1)
	{
		usleep (1);
		time_out++;
		if (time_out > 1000000)
			exit(1);
	}
}

void	char_feeder(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		bit_shooter(str[i], 7, pid);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	int					x;
	struct sigaction	sa;

	if (argv[1] == NULL)
		exit(1);
	pid = ft_atoi(argv[1]);
	if (pid == -1)
		exit(1);
	x = 2;
	sa.sa_handler = &flow_control;
	sigaction(SIGUSR1, &sa, NULL);
	while (x < argc)
	{
		char_feeder(argv[x], pid);
		x++;
	}
	return (0);
}
