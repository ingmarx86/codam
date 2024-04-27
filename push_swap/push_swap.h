/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:14:24 by inoteboo          #+#    #+#             */
/*   Updated: 2023/04/04 11:49:59 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <stdarg.h>

int		quicksort(int stack_a[], int stack_b[], int length);
void	small_sort(int stack_a[], int stack_b[], int len[]);
void	qs_recursion_a(int stack_a[], int stack_b[], int high, int len[]);
void	qs_recursion_b(int stack_a[], int stack_b[], int high, int len[]);
int		three_sort_a(int stack_a[], int stack_b[], int len[]);
int		three_sort_b(int stack_a[], int stack_b[], int len[]);
int		a_sorted(int stack_a[], int length);
int		b_sorted(int stack_b[], int length);
void	swap_a(int stack_a[]);
void	swap_b(int stack_b[]);
int		rotate_a(int array[], int high);
int		rotate_b(int array[], int high);
int		two_sort_a(int stack_a[]);
int		two_sort_b(int stack_a[], int stack_b[], int len[]);
void	push_to_a(int stack_a[], int stack_b[], int len[]);
void	push_to_b(int stack_a[], int stack_b[], int len[]);
int		reverse_rotate_b(int array[], int len);
int		reverse_rotate_a(int array[], int len);
int		rotate_check_a(int stack[], int p_val, int count, int high);
int		rotate_check_b(int stack[], int p_val, int count, int high);
int		dup_check(int array_a[], int len);
int		pivot_finder(int array[], int stack_x[], int high);
int		insertionsort(int segment[], int length);
int		ft_atoi(const char *str);
void	error(int stack_a[], int stack_b[], int which_one);

#endif
