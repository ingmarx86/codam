/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:36:36 by inoteboo          #+#    #+#             */
/*   Updated: 2022/11/26 09:50:37 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*ptr1;
	char		*ptr2;

	ptr1 = (const char *)src;
	ptr2 = (char *)dst;
	if ((ptr1 == NULL) && (ptr2 == NULL))
		return (NULL);
	while (n)
	{
		*(ptr2++) = *(ptr1++);
		n--;
	}
	return (dst);
}

// int	main(void)
// {
// 	int		len;
// 	char	d[] = "aa";
// 	char	s[] = "bbb";

// 	len = 4;
// 	printf("%s\n", ft_memcpy(d, s, 2));
// 	printf("%s\n", memcpy(d, s, 2));
// }
