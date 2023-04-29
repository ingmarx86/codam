/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:37:16 by inoteboo          #+#    #+#             */
/*   Updated: 2022/12/16 14:52:54 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_ptr(int n, int *p)
{
	if (n == -2147483648)
	{
		ft_putstr_ptr("-2147483648", p);
		return ;
	}
	if (n < 0)
	{
	n = -n;
		ft_putchar_ptr('-', p);
	}
	if (n > 9)
		ft_putnbr_ptr(n / 10, p);
	if (*p == -1)
		return ;
	ft_putchar_ptr((n % 10) + '0', p);
}

// int main(void)
// {
//     ft_putnbr_fd(83, 1);
// }