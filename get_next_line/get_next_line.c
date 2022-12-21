/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:47:19 by inoteboo          #+#    #+#             */
/*   Updated: 2022/12/21 17:23:38 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*buffer_fill(int fd, int *p, int *x)
{
	int		i;
	int		end;
	char	*buffer;

	end = 0;
	i = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (i < BUFFER_SIZE)
	{	
		if ((read(fd, buffer, 1)) == 0)
			return ((*p = 2), buffer - i);
		if (*buffer == '\n')
			return ((*p = 1), buffer - i);
		*x += 1;
		i++;
		buffer++;
	}
	return ((free (buffer)), buffer - i);
}

char	*get_next_line(int fd)
{
	char	*line_store;
	int		i;
	int		end;
	int		*p;
	int		*x;

	p = &end;
	x = &i;
	i = 0;
	end = 0;
	
	line_store = malloc(sizeof(char) * 1000);
	while (end == 0)
	{
		strlcat(line_store, (buffer_fill(fd, p, x)), i + 1);
		//free (buffer_fill(fd, p, x));
	}
	if (end == 2)
		return (NULL);
	return (/*(free (line_store)),*/ line_store);
}

int	main(void)
{
	int	fd;

	fd = open ("log.txt", O_RDONLY);
	printf("line 1:%s\n", get_next_line(fd));
	sleep (1);
	printf("line 2:%s\n", get_next_line(fd));
	sleep (1);
	printf("line 3:%s\n", get_next_line(fd));
	sleep (1);
	printf("line 4:%s\n", get_next_line(fd));
	sleep (1);
	printf("line 5:%s\n", get_next_line(fd));
	sleep (1);
	printf("line 6:%s\n", get_next_line(fd));
	close (fd);
	return (0);
}
