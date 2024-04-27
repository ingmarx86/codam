/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 07:45:58 by inoteboo          #+#    #+#             */
/*   Updated: 2023/03/01 11:26:52 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *line_store)
{
	char	*line;
	int		i;

	i = 0;
	while (line_store[i++])
		if (line_store[i] == '\n')
			break ;
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
		return (NULL);
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
	if (rest == NULL)
		return (free(line_store), NULL);
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
