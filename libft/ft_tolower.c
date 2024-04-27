/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:18:41 by inoteboo          #+#    #+#             */
/*   Updated: 2022/11/26 10:29:42 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c +32;
	return (c);
}

// int	main(void)
// {
// 	int	a = 'G';
// 	int	b = 'G';

// 	printf("%c\n", ft_tolower(a));
// 	printf("%c\n", tolower(b));
// }
