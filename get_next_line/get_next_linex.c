/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:47:19 by inoteboo          #+#    #+#             */
/*   Updated: 2023/02/28 11:34:39 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
//#include <string.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*ft_strdup(const char *line_store)
{
	char	*line;
	int		i;

	i = 0;
	while (line_store[i])
		{
		i++;
		if (line_store[i] == '\n')
		break;
		}
	line = ft_calloc((i + 2), sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (line_store[i] != '\n' && line_store[i])
	{
	line[i] = line_store[i];
	i++;
	}
	if (line_store[i] == '\n')
	{
	line[i] = '\n';
	i++;
	}
	line[i] = '\0';
		return (line);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

int	ft_find_end(const void *str, int x)
{
	unsigned char	*ptr;
	int				i;

	i = 0;
	ptr = (unsigned char *)str;
	while (i < x)
	{
		if (*ptr == '\n' || *ptr == '\0')
			return (1);
		ptr++;
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *line_store)
{
	unsigned int	i;
	int				x;
	char			*rest;

	rest = malloc(sizeof(char) * (ft_strlen(line_store) + 3));
	i = 0;
	x = 0;
	while (line_store[i] != '\n' && line_store[i])
		i++;
	if (line_store[i] == '\n')
		i++;
	while (line_store[i])
	{
		rest[x] = line_store[i];
		x++;
		i++;
	}
	rest[x] = '\0';
	free (line_store);
	return (rest);
}

char	*ft_strjoin(char *line_store, char *buffer)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	x;

	i = 0;
	x = 0;
	ptr = ft_calloc(sizeof(char) * (ft_strlen(line_store) + ft_strlen(buffer) + 2), 1);
	if (ptr == NULL)
		return (NULL);
	if (*line_store != '\0')
		while (line_store[i])
		{
			ptr[i] = line_store[i];
			i++;
		}
	while (buffer[x])
	{
		ptr[i] = buffer[x];
		i++;
		x++;
	}
	free (line_store);
	ptr[i] = '\0';
	return (ptr);
}

char	*buffer_fill(int fd, char *line_store)
{
	int			i;
	char		*buffer;
	int x;

	i = 0;
	x = 1;
	buffer = NULL;
	
	while (i == 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		x = read(fd, buffer, BUFFER_SIZE);
		printf("the value of x = %i", x);
		if (x == -1)
			return (free (line_store), NULL);
		buffer[x] = '\0';
		line_store = ft_strjoin(line_store, buffer);
		if (line_store == NULL)
			return (NULL);
		i = ft_find_end(buffer, BUFFER_SIZE);
		free (buffer);
	}
	return (line_store);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char *line_store;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL); 
	if (line_store == NULL)
	line_store = ft_calloc(BUFFER_SIZE + 1 ,sizeof(char));
	if (line_store == NULL)
		return (NULL);
	line_store = buffer_fill(fd, line_store);
	if (line_store == NULL)
		return (NULL);
	line = ft_strdup(line_store);
	if (*line == '\0')
		{
		free (line_store);
		line_store = NULL;
		return (free (line), NULL);
		}
	line_store = ft_strcpy(line_store);
	if (*line_store == '\0')
		{
		free (line_store);
		line_store = NULL;
		}
		
	return (line);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("log.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 			if (BUFFER_SIZE > 100)
// 			{
// 			char *temp;
// 			do {
// 				temp = get_next_line(fd);
// 				free(temp);
// 			} while (temp != NULL);
// 			}
// 	printf("%s", get_next_line(fd));
// 	// close (fd);
// 	// fd = open("log.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close (fd);
// 	return (0);
// }
