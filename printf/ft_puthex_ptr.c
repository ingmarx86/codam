/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:37:16 by inoteboo          #+#    #+#             */
/*   Updated: 2022/12/18 11:06:01 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_ptr(unsigned int n, int *p)
{
	if (n >= 0x10)
		ft_puthex_ptr(n / 0x10, p);
	if (*p < 0)
		return ;
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