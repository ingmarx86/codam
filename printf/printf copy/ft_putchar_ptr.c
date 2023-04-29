/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:09:46 by inoteboo          #+#    #+#             */
/*   Updated: 2022/12/17 12:14:33 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_ptr(char c, int *p)
{
	if (write(1, &c, 1) == -1)
	{
		*p = -1;
		return ;
	}
	else
		*p += 1;
}

// int	main(void)
// {
// 	ft_putchar_fd('d', 2);
// }
