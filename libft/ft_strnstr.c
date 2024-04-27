/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:28:51 by inoteboo          #+#    #+#             */
/*   Updated: 2022/11/26 10:27:22 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		x;
	size_t	i;
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *)str;
	ptr2 = (char *)to_find;
	i = 0;
	x = 0;
	if (*to_find == 0)
		return (ptr1);
	x = ft_strlen(to_find);
	while (*ptr1 && (i + x) <= len)
	{
		if (*ptr1 == *ptr2)
		{
			if (!ft_strncmp(ptr1, ptr2, x))
				return ((char *)ptr1);
		}
		ptr1++;
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	a[] = "1: one 10: ten";
// 	char	b[] = "10";
// 	size_t	x = 8;

// 	//printf("%s\n", ft_strnstr(a, b, x));
// 	printf("%s\n", strnstr(a, b, x));
// }
