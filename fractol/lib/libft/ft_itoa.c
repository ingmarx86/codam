/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:40:28 by inoteboo          #+#    #+#             */
/*   Updated: 2022/11/26 09:28:16 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n, int i)
{
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*copy(int temp_n, int x, int i, int max)
{
	char	*str;

	str = malloc((sizeof(char)) * (i + 1));
	if (str == 0)
		return (NULL);
	str[i] = '\0';
	if (x == 1)
	str[0] = '-';
	i--;
	while (i >= 0 && temp_n >= 10)
	{
		if (max == 1)
		{
		str[i] = temp_n % 10 + '1';
		max = 0;
		temp_n = temp_n / 10;
		i--;
		}
		str[i] = temp_n % 10 + '0';
		temp_n = temp_n / 10;
		i--;
	}
	str[i] = temp_n + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	int	i;
	int	temp_n;
	int	x;
	int	max;

	max = 0;
	x = 0;
	i = 1;
	if (n == -2147483648)
	{
		max = 1;
		n = n +1;
	}
	if (n < 0)
	{
		n = -n;
		i = i + 1;
		x = 1;
	}
	temp_n = n;
	i = count(n, i);
	return (copy(temp_n, x, i, max));
}

// int	main(void)
// {
// 	printf("%s\n", (ft_itoa(-2147483648)));
// }
