/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:18:24 by inoteboo          #+#    #+#             */
/*   Updated: 2022/12/18 12:24:32 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_write(va_list args, char type, int *p)
{
	if (type == 'd' || type == 'i')
		ft_putnbr_ptr((va_arg(args, int)), p);
	else if (type == 's')
		ft_putstr_ptr((va_arg(args, char *)), p);
	else if (type == 'c')
		ft_putchar_ptr((va_arg(args, int)), p);
	else if (type == 'x')
		ft_puthex_ptr((va_arg(args, unsigned int)), p);
	else if (type == 'X')
		ft_puthexx_ptr((va_arg(args, unsigned int)), p);
	else if (type == 'u')
		ft_putnbru_ptr((va_arg(args, unsigned int)), p);
	else if (type == 'p')
		ft_putptr_ptr((va_arg (args, unsigned long)), 0, p);
	else
		ft_putchar_ptr(type, p);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		x;
	int		*p;
	va_list	args;

	i = 0;
	x = 0;
	p = &x;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			format_write(args, str[i + 1], p);
			i++;
		}
		else
			ft_putchar_ptr(str[i], p);
		i++;
		if (*p < 0)
			return (-1);
	}
	va_end(args);
	return (x);
}

// int	main(void)
// {
// 	int	a = 7;
// 	int	*p = &a;

// 	//printf("%s", NULL);
// 	ft_printf("\n%d %s %c %x %X %X %u %p %k %% \n", 123
// , "AbC", 'c', 0xa123b, 0xa123b, 3145, 24, p, 1);
// 	printf("\n%d %s %c %x %X %X %u %p %k %% \n", 123
// , "AbC", 'c', 0xa123b, 0xa123b, 3145, 24, p, 1);
// }
