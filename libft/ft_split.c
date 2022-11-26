/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:20:05 by inoteboo          #+#    #+#             */
/*   Updated: 2022/11/26 08:29:40 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freearr(char **arr, int row)
{
	while (row >= 0)
	{
		free (arr[row]);
		row--;
	}
	free (arr);
	return (NULL);
}

char	**substr(char **arr, const char *s, int row, char c)
{
	int		i;
	int		col;

	i = 0;
	col = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
		i++;
		col++;
		}
		arr[row] = ft_substr(s, i - col, col);
		if (arr[row] == NULL)
		{
		arr = freearr(arr, row);
			return (NULL);
		}
		while (s[i] == c && s[i] != '\0')
		i++;
		if ((s[i - 1] == c && s[i] != c) || s[i] == '\0')
		row++;
		col = 0;
	}
	return (arr);
}

static char	**memalloc(const char *s, int row, char c)
{
	char	**arr;

	arr = (char **)ft_calloc((row + 1), (sizeof(char *)));
	if (arr == NULL)
		return (NULL);
	row = 0;
	arr = substr(arr, s, row, c);
	return (arr);
}

static int	rowcounter(const char *s, char c)
{
	int		i;
	int		row;

	i = 0;
	row = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || s[i + 1] == '\0')
		row++;
		i++;
	}
	return (row);
}

char	**ft_split(const char *s, char c)
{
	int		row;
	char	**arr;

	while (*s == c && *s != '\0')
	s++;
	row = rowcounter(s, c);
	arr = memalloc(s, row, c);
	return (arr);
}

// int	main(void)
// {
// 	char	**arr;
// 	char	*s = "^^^1^^2a,^^^^3^^^^--h^^^^";

// 	arr = ft_split(s, '^');
// 	printf("arr[0] = %s\n", arr[0]);
// 	printf("arr[1] = %s\n", arr[1]);
// 	printf("arr[2] = %s\n", arr[2]);
// 	printf("arr[3] = %s\n", arr[3]);
// 	printf("arr[4] = %s\n", arr[4]);
// 	return (0);
// }
