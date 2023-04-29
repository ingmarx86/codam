/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:52:58 by inoteboo          #+#    #+#             */
/*   Updated: 2022/12/16 14:54:55 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_ptr(char *s, int *p)
{
	int	i;

	if (*p == -1)
		return ;
	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
		{
			*p = -1;
			return ;
		}
		else
			*p += 6;
		return ;
	}
	i = ft_strlen(s);
	if (write(1, s, i) == -1)
	{
		*p = -1;
		return ;
	}
	else
		*p += i;
}

// int	main(void)

// {
// 	ft_putstr_fd("jyhtfjy", 2);
// }
