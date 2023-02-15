/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:47:19 by inoteboo          #+#    #+#             */
/*   Updated: 2023/02/15 14:13:49 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
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

int	ft_find_char(const void *str, int x)
{
	unsigned char	*ptr;
	int				i;
	
	i = 0;
	ptr = (unsigned char *)str;
	if (*ptr == '\n' || *ptr == '\0')
		return (-1);
	while (i < x)
	{
		if (*ptr == '\n' || *ptr == '\0')
			return (i);
		ptr++;
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	i;
	int x;
	char			*ptr;
	ptr = calloc(sizeof(char) * (ft_strlen(src) + 10), 1);
	i = 0;
	x = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
		if (src[i - 1] == '\n')
		break;
	}
	dest[i] = '\0';
	while (src[i])
	{
		ptr[x] = src[i];
		x++;
		i++;
	}
	free (src);
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	x;

	i = 0;
	x = 0;
	ptr = calloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 10), 1);
	
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
	free (s1);
	ptr[i] = '\0';
	return (ptr);
}

char	*buffer_fill(int fd)
{
	int			i;
	char		*buffer;
	static char	*line_store;
	char		*ret_buff;
	int			x;
	
	
	i = 0;
	ret_buff = NULL;
	buffer = NULL;

	if (line_store == NULL)
		line_store = calloc(sizeof(char) * 1, 1);
	x = ft_strlen(line_store);
	while (i == 0)
	{
		buffer = calloc(sizeof(char) * (BUFFER_SIZE + 10), 1);
		x += read(fd, buffer, BUFFER_SIZE);
		if (x <= 0)
			{
			line_store = NULL;
			free (line_store);
			free (buffer);
			return (NULL);
			}
		line_store = ft_strjoin(line_store, buffer);
		i =  ft_find_char(buffer, BUFFER_SIZE);
		free (buffer);
	}
	if (i == -1)
		i = 0;
	ret_buff = malloc(sizeof(char) * x + 2);
	line_store = ft_strcpy(ret_buff, line_store);
	if (line_store == '\0')
		free (line_store);
	return (ret_buff);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return NULL;

	line = buffer_fill(fd);
	
	return (line);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("log.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
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
