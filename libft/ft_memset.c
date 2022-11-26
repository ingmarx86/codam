/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:36:36 by inoteboo          #+#    #+#             */
/*   Updated: 2022/11/26 09:52:11 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n)
	{
		*(ptr++) = (char)c;
		n--;
	}
	return (s);
}

// int	main(void)
// {
// 	char	ptr1[] = "hjdfdfgshgs";
// 	char	ptr2[] = "hjdfdfgshgs";

// 	printf("%s\n", ft_memset(ptr1 + 3, 'x', 5));
// 	printf("%s\n", memset(ptr2 + 3, 'x', 5));
// 	printf("%s\n", ptr1);
// 	printf("%s\n", ptr2);
// }
