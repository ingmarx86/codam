/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:14:24 by inoteboo          #+#    #+#             */
/*   Updated: 2022/12/18 11:09:14 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar_ptr(char c, int *p);
void	ft_puthex_ptr(unsigned int n, int *p);
void	ft_puthexx_ptr(unsigned int n, int *p);
void	ft_putnbr_ptr(int n, int *p);
void	ft_putnbru_ptr(unsigned int n, int *p);
void	ft_putptr_ptr(unsigned long n, int i, int *p);
void	ft_putstr_ptr(char *s, int *p);
size_t	ft_strlen(const char *str);

#endif
