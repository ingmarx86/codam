/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:37:16 by inoteboo          #+#    #+#             */
/*   Updated: 2022/12/18 11:01:13 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbru_ptr(unsigned int n, int *p)
{
	if (n > 9)
	{
		ft_putnbru_ptr(n / 10, p);
		if (*p < 0)
			return ;
	}
	ft_putchar_ptr((n % 10) + '0', p);
}

// int main(void)
// {
//     ft_putnbru_fd(1, 1);
// 	printf("\n%u", 83);
// }