/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:36:36 by inoteboo          #+#    #+#             */
/*   Updated: 2022/11/26 09:22:03 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	x;
	char	*ptr;

	x = count * size;
	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (0);
	while ((x) > 0)
	{
		ptr[i] = '\0';
		i++;
		x--;
	}
	return ((void *)ptr);
}

// int	main(void)
// {
// 	printf("ft_calloc%s\n", ft_calloc(0, 3));
// 	printf("calloc   %s\n", calloc(0, 3));
// }
