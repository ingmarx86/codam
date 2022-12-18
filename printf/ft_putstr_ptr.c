/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:52:58 by inoteboo          #+#    #+#             */
/*   Updated: 2022/12/18 11:13:48 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_ptr(char *s, int *p)
{
	int	i;

	if (s == NULL)
	{
		*p += (write(1, "(null)", 6));
		return ;
	}
	i = ft_strlen(s);
	*p += (write(1, s, i));
}

// int	main(void)

// {
// 	ft_putstr_fd("jyhtfjy", 2);
// }
