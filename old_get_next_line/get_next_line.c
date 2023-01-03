/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:47:19 by inoteboo          #+#    #+#             */
/*   Updated: 2023/01/03 09:38:48 by inoteboo         ###   ########.fr       */
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

size_t	ft_strlen(const char *str)
{
	if (str == NULL)
		return (0);
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	x;

	i = 0;
	x = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	
	if (ptr == NULL)
		return (NULL);
		
	if (s1 != NULL)
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
	
	while (s2[x])
	{
		ptr[i] = s2[x];
		i++;
		x++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*buffer_fill(int fd, int *end_ptr)
{
	int		i;
	int		end;
	char	*buffer;
	char	*line_store;
	
	i = 0;
	end = 0;
	line_store = NULL;
	buffer = NULL;
	
	while(*end_ptr == 0)
	{
		// printf("buff adres B = %p\n", buffer);
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		// printf("buff adres A = %p\n", buffer);
		while (i < BUFFER_SIZE)
		{	
			if ((read(fd, buffer, 1)) == 0)
			{
				*(buffer) = '\0';
				*end_ptr = 2;
				break;
			}
			if (*buffer == '\n')
			{
				*(buffer + 1) = '\0';
				*end_ptr = 1;
				break;
			}
			i++;
			buffer++;
			
		}
		 
		// printf("buff free adres = %p\n", buffer - i);
		line_store = ft_strjoin(line_store, buffer - i);
		free (buffer - i);
		buffer = NULL;
		i = 0;
	}

	return (line_store);
}

char	*get_next_line(int fd)
{
	char	*line_store;
	int		end;
	int		*end_ptr;
	
	end_ptr = &end;
	end = 0;
	
	line_store = buffer_fill(fd, end_ptr);
	
	if (end == 2)
		return (NULL);
	return (line_store);
}

int	main(void)
{
	int	fd;

	fd = open("log.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	printf("line 1:%s", get_next_line(fd));
	sleep (1);
	printf("line 2:%s", get_next_line(fd));
	// sleep (1);
	// printf("line 3:%s", get_next_line(fd));
	// sleep (1);
	// printf("line 4:%s", get_next_line(fd));
	// sleep (1);
	// printf("line 5:%s", get_next_line(fd));
	// sleep (1);
	// printf("line 6:%s", get_next_line(fd));
	close (fd);
	return (0);
}
