/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:49:54 by inoteboo          #+#    #+#             */
/*   Updated: 2023/05/28 11:34:04 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	long long int	c;

	i = 0;
	c = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
	str++;
	if (!((*str >= 48 && *str <= 57) || *str == '-' || *str == '+'))
		return (0);
	if (*str == '-' || *str == '+')
	{
		i = *str;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		c = (c * 10) + (*str - 48);
		str++;
	}
	if (i == 45)
		c = -c;
	return (c);
}

// int	main(void)
// {
// 	char	str[] = " -99999999";

// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// }
