/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:36:36 by inoteboo          #+#    #+#             */
/*   Updated: 2022/11/26 10:06:14 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// int	main(void)
// {
// 	int		len;
// 	char	d[] = "aaaaaaaaaa";
// 	char	s[] = "bbbbbbb";

// 	len = 0;
// 	printf("%zu\n", (ft_strlcpy(d, s, len)));
// 	//printf("%zu\n", (strlcpy(d, s, len)));
// 	printf("%s\n", d);
// }
