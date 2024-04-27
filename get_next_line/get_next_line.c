/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:47:19 by inoteboo          #+#    #+#             */
/*   Updated: 2023/03/01 11:33:54 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*ft_strjoin(char *line_store, char *buffer)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	x;

	i = 0;
	x = 0;
	ptr = ft_calloc(1, (ft_strlen(line_store) + ft_strlen(buffer) + 1));
	if (ptr == NULL)
		return (free(line_store), NULL);
	if (*line_store != '\0')
	{
		while (line_store[i])
		{
			ptr[i] = line_store[i];
			i++;
		}
	}
	while (buffer[x])
	{
		ptr[i] = buffer[x];
		x++;
		i++;
	}
	ptr[i] = '\0';
	return (free (line_store), ptr);
}

char	*buffer_fill(int fd, char *line_store)
{
	int			i;
	char		*buffer;
	int			x;

	i = 0;
	x = 1;
	buffer = NULL;
	while (i == 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return (free(line_store), NULL);
		x = read(fd, buffer, BUFFER_SIZE);
		if (x == -1)
			return (free (buffer), free(line_store), NULL);
		buffer[x] = '\0';
		line_store = ft_strjoin(line_store, buffer);
		if (line_store == NULL)
			return (free(buffer), NULL);
		i = ft_find_end(buffer, BUFFER_SIZE);
		free (buffer);
	}
	return (line_store);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_store;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (line_store == NULL)
		line_store = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (line_store == NULL)
		return (NULL);
	line_store = buffer_fill(fd, line_store);
	if (line_store == NULL)
		return (NULL);
	line = ft_strdup(line_store);
	if (line == NULL)
		return (NULL);
	if (*line == '\0')
		return (free(line), free(line_store), line_store = NULL, NULL);
	line_store = ft_strcpy(line_store);
	if (line_store == NULL)
		return (free(line), NULL);
	if (*line_store == '\0')
		return (free(line_store), line_store = NULL, line);
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
