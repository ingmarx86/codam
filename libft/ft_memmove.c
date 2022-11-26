/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:36:36 by inoteboo          #+#    #+#             */
/*   Updated: 2022/11/26 09:51:26 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	i = 0;
	ptr1 = (unsigned char *)src;
	ptr2 = (unsigned char *)dst;
	if ((ptr1 == NULL) && (ptr2 == NULL))
		return (dst);
	if (src < dst)
	{
		while (len--)
			ptr2[len] = ptr1[len];
	}
	else
	{
		while (len--)
		*ptr2++ = *ptr1++;
	}
	return (dst);
}

// int	main(void)
// {
// 	int		len;
// 	char	d[] = "aaaaaa";
// 	char	s[] = "01234";

// 	len = 3;
// 	printf("result ft = %s\n", ft_memmove(d, s, len));
// 	printf("result    = %s\n", memmove(d, s, len));
// }
