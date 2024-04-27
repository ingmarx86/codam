/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 08:08:36 by inoteboo          #+#    #+#             */
/*   Updated: 2023/05/21 13:38:58 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	write_int(int n)
{
	int	x;

	if (n > 9)
		write_int(n / 10);
	x = (n % 10) + '0';
	write(1, &x, 1);
}

void	handle_sigusr(int sig, siginfo_t *info, void *context)
{
	static char	ascii = 0;
	static int	count = 0;
	static int	client_pid = 0;
	void		*x;

	x = context;
	if (info->si_pid != 0)
		client_pid = info->si_pid;
	if (sig == SIGUSR1)
		ascii += 1 << (7 - count);
	count += 1;
	if (count == 8 && (ascii >= 32 && ascii <= 126))
	{
		write(1, &ascii, 1);
		ascii = 0;
		count = 0;
	}
	else if (count == 8)
	{
		ascii = 0;
		count = 1;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_sigusr;
	write_int(pid);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
