/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexx_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:37:16 by inoteboo          #+#    #+#             */
/*   Updated: 2022/12/16 14:52:09 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexx_ptr(unsigned int n, int *p)
{
	if (n >= 0x10)
	{
		ft_puthexx_ptr(n / 0x10, p);
		if (*p == -1)
			return ;
	}
	if ((n % 0x10) <= 0x9)
		ft_putchar_ptr((n % 0x10) + 48, p);
	else
		ft_putchar_ptr((n % 0x10) + 55, p);
}

// int main(void)
// {
//     ft_puthexx_fd(0xcd48a85, 1);
// 	printf("\nprintf hex == %x\n", 0xf25ab);
// }