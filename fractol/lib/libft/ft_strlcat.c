/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:16:52 by inoteboo          #+#    #+#             */
/*   Updated: 2022/11/26 10:05:42 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	i;
	int				x;
	size_t			s;

	i = ft_strlen(dest);
	x = 0;
	s = i;
	if (size == 0)
		return (ft_strlen(src));
	while (src[x] && i < (size - 1))
	{
		dest[i] = src[x];
		x++;
		i++;
	}
	dest[i] = '\0';
	if (s <= size)
		return (ft_strlen(src) + s);
	return (ft_strlen(src) + size);
}

// int	main(void)
// {
// 	char			d[20] = "qrstuvwxyz";
// 	char			s[] = "abcd";
// 	unsigned int	size = 20;

// 	printf("%zu\n", ft_strlcat(d, s, size));
// 	//printf("%zu\n", strlcat(d, s, size));
// 	printf("%s\n", d);
// }
