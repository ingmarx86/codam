/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:37:16 by inoteboo          #+#    #+#             */
/*   Updated: 2022/12/16 14:54:30 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_ptr(unsigned long long n, int i, int *p)
{
	if (i == 0)
	{
		if (write (1, "0x", 2) == -1)
		{
		*p = -1;
			return ;
		}
		i++;
		*p += 2;
	}
	if (n >= 0x10)
		ft_putptr_ptr(n / 0x10, i, p);
	if ((n % 0x10) <= 0x9)
		ft_putchar_ptr((n % 0x10) + 48, p);
	else
		ft_putchar_ptr((n % 0x10) + 87, p);
}

// int main(void)
// {
// 	int a = 7;
// 	int *p = &a;

//     ft_puthex_fd(p, 1);
// 	printf("\nprintf hex == %p\n", p);
// }