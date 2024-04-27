/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:28:51 by inoteboo          #+#    #+#             */
/*   Updated: 2022/11/26 10:27:57 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

ptr = (char *)s;
i = ft_strlen(ptr);
ptr = ptr + i;
	while (i >= 0)
	{
		if ((char)*ptr == (char)c)
			return ((char *)ptr);
		ptr--;
		i--;
	}
	return (0);
}

// int	main(void)
// {
// 	const char	s[] = "teste";
// 	const int	c = 'e';

// 	printf("ft = %s\n", ft_strrchr(s, c));
// 	printf("or = %s\n", strrchr(s, c));
// }
