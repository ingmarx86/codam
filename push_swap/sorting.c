/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:26:18 by inoteboo          #+#    #+#             */
/*   Updated: 2023/04/04 08:25:02 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	two_sort_a(int stack_a[])
{
	if (stack_a[0] > stack_a[1])
		swap_a(stack_a);
	return (0);
}

int	two_sort_b(int stack_a[], int stack_b[], int len[])
{
	if (stack_b[0] < stack_b[1])
		swap_b(stack_b);
	push_to_a(stack_a, stack_b, len);
	push_to_a(stack_a, stack_b, len);
	return (0);
}

int	three_sort_a(int stack_a[], int stack_b[], int len[])
{
	if (a_sorted(stack_a, 3) == 1)
		return (0);
	if (stack_a[0] < stack_a[1])
	{
		push_to_b(stack_a, stack_b, len);
		swap_a(stack_a);
		push_to_a(stack_a, stack_b, len);
		if (a_sorted(stack_a, 3) == 1)
			return (0);
	}
	swap_a(stack_a);
	if (a_sorted(stack_a, 3) == 1)
		return (0);
	push_to_b(stack_a, stack_b, len);
	swap_a(stack_a);
	push_to_a(stack_a, stack_b, len);
	if (a_sorted(stack_a, 3) == 1)
		return (0);
	swap_a(stack_a);
	return (0);
}

int	three_sort_b(int stack_a[], int stack_b[], int len[])
{
	int	count;

	count = 0;
	while (count < 3)
	{
		if (stack_a[0] > stack_a[1] && len[1] > 1)
			swap_a(stack_a);
		if (stack_b[0] < stack_b[1] && count < 2)
			swap_b(stack_b);
		push_to_a(stack_a, stack_b, len);
		count++;
	}
	return (0);
}

int	insertionsort(int segment[], int length)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < length)
	{
		j = i - 1;
		key = segment[i];
		while (j >= 0 && segment[j] > key)
		{
			segment[j + 1] = segment[j];
			j = j - 1;
		}
		segment[j + 1] = key;
		i++;
	}
	return (segment[length / 2]);
}
