/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:42:26 by inoteboo          #+#    #+#             */
/*   Updated: 2023/04/04 09:14:37 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_check_a(int stack[], int p_val, int count, int high)
{
	int	i;

	i = 0;
	while (i <= high - count)
	{
		if (stack[i] > p_val)
			i++;
		else
			return (1);
	}
	return (0);
}

int	rotate_check_b(int stack[], int p_val, int count, int high)
{
	int	i;

	i = 0;
	while (i <= high - count)
	{
		if (stack[i] < p_val)
			i++;
		else
			return (1);
	}
	return (0);
}

int	dup_check(int stack_a[], int len)
{
	int	i;
	int	x;

	i = 0;
	while (i < len)
	{
		x = 0;
		while (x < len)
		{
			if (i != x && stack_a[i] == stack_a[x])
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}
