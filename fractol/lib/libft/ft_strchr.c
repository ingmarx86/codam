/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:28:51 by inoteboo          #+#    #+#             */
/*   Updated: 2022/11/26 09:54:47 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return ((char *)s - 1);
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

// int	main(void)
// {
// 	const char	s[] = "teste";
// 	const int	c = 'e' + 256;
// 	printf("%s\n", ft_strchr(s, c));
// 	printf("%s\n", strchr (s, c));
// 	printf("%d\n", 'e' + 256);
// 	printf("%d\n", 'e' + 512);
// 	printf("%d\n", 'e' + 1024);
// 	printf("%c\n", 357);
// 	printf("%c\n", 613);
// 	printf("%c\n", 1125);
// }
