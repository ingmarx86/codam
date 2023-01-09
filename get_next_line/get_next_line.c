/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:47:19 by inoteboo          #+#    #+#             */
/*   Updated: 2023/01/06 16:39:50 by inoteboo         ###   ########.fr       */
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

int	ft_find_char(const void *str, int c)
{
	unsigned char	*ptr;
	int				i;

	i = 0;

	ptr = (unsigned char *)str;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
			return (i);
		ptr++;
		i++;
	}
	return (0);
}

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

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
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
	int	i;
	int			end;
	char		*buffer;
	static char	*line_store;
	char		*ret_buff;
	
	i = 0;
	end = 0;
	ret_buff = NULL;
	buffer = NULL;
	printf("linestore0 =%p\n", line_store);
	if (!line_store)
	line_store = malloc(sizeof(char) * 1000000000);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (end == 0)
	{	
		
		if ((read(fd, buffer, BUFFER_SIZE)) == 0)
		{
			*end_ptr = 2;
			break;
		}
		//printf("linestore =%s\n", line_store);
		line_store = ft_strjoin(line_store, buffer);
		i =  ft_find_char(line_store, '\n');
		if (i != 0)
			end = 1;
	}
	
	free(buffer);
	ret_buff = malloc(sizeof(char) * (ft_strlen(line_store) + 1));
	ft_strlcpy(ret_buff, line_store, i + 2);
	line_store = line_store + (i + 1);
	// printf("linestore2 =%p\n", ret_buff);
		
	return (ret_buff);
}

char	*get_next_line(int fd)
{
	char	*line_store;
	int		end;
	int		*end_ptr;
	
	end_ptr = &end;
	end = 0;
	
	line_store = buffer_fill(fd, end_ptr);
	//printf("linestore3 =%p\n", line_store);
	
	
	if (end == 2)
		return (NULL);
	return (line_store);
}

int	main(void)
{
	int	fd;

	fd = open("log.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	//printf("linestore4 =%p\n", get_next_line(fd));
	free (get_next_line(fd));
	sleep (1);
	printf("%s", get_next_line(fd));
	free (get_next_line(fd));
	sleep (1);
	printf("%s", get_next_line(fd));
	free (get_next_line(fd));
	sleep (1);
	printf("%s", get_next_line(fd));
	free (get_next_line(fd));
	sleep (1);
	printf("%s", get_next_line(fd));
	free (get_next_line(fd));
	sleep (1);
	printf("%s", get_next_line(fd));
	free (get_next_line(fd));
	close (fd);
	return (0);
}
