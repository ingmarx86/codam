/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:34:28 by inoteboo          #+#    #+#             */
/*   Updated: 2023/04/04 11:16:06 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition_a(int stack_a[], int stack_b[], int high, int len[])
{
	int	count;
	int	start_length;
	int	rotate_count;
	int	p_val;

	count = 0;
	start_length = len[1];
	rotate_count = 0;
	p_val = pivot_finder(stack_a, stack_a, high);
	while (count <= high)
	{
		if (stack_a[0] <= p_val)
			push_to_b(stack_a, stack_b, len);
		else
		{
			if (!rotate_check_a(stack_a, p_val, count, high))
				break ;
			rotate_count += rotate_a(stack_a, (len[1] - 1));
		}
		count++;
	}
	while (rotate_count > 0 && (start_length - high) > 1)
		rotate_count -= reverse_rotate_a(stack_a, (len[1] - 1));
	return (high - (start_length - len[1] - 1));
}

int	partition_b(int stack_a[], int stack_b[], int high, int len[])
{
	int	count;
	int	rotate_count;
	int	start_length;
	int	p_val;

	count = 0;
	rotate_count = 0;
	start_length = len[1];
	p_val = pivot_finder(stack_b, stack_a, high);
	while (count <= high)
	{
		if (stack_b[0] >= p_val)
			push_to_a(stack_a, stack_b, len);
		else
		{
			if (!rotate_check_b(stack_b, p_val, count, high))
				break ;
			rotate_count += rotate_b(stack_b, len[0] - (len[1] + 1));
		}
		count++;
	}
	while (rotate_count > 0 && len[0] - start_length - high > 1)
		rotate_count -= reverse_rotate_b(stack_b, len[0] - (len[1] + 1));
	return (len[1] - start_length);
}

void	qs_recursion_a(int stack_a[], int stack_b[], int high, int len[])
{
	int	p_index;

	if (high == 1)
		p_index = two_sort_a(stack_a);
	if (high == 2)
		p_index = three_sort_a(stack_a, stack_b, len);
	if (high > 2 && !a_sorted(stack_a, high + 1))
	{
		p_index = partition_a(stack_a, stack_b, high, len);
		qs_recursion_a(stack_a, stack_b, (p_index - 1), len);
		qs_recursion_b(stack_a, stack_b, (high - (p_index)), len);
	}
}

void	qs_recursion_b(int stack_a[], int stack_b[], int high, int len[])
{
	int	p_index;

	if (high == 0)
		push_to_a(stack_a, stack_b, len);
	if (high == 1)
		p_index = two_sort_b(stack_a, stack_b, len);
	if (high == 2)
		p_index = three_sort_b(stack_a, stack_b, len);
	if (high > 2)
	{
		p_index = partition_b(stack_a, stack_b, high, len);
		qs_recursion_a(stack_a, stack_b, (p_index - 1), len);
		qs_recursion_b(stack_a, stack_b, (high - (p_index)), len);
	}
}

int	pivot_finder(int array[], int stack_x[], int high)
{
	int	x;
	int	*segment;

	segment = malloc(sizeof(int) * (high + 1));
	if (segment == NULL)
		return (error(array, stack_x, 2), -1);
	x = 0;
	while (x <= high)
	{
		segment[x] = array[x];
		x++;
	}
	x = insertionsort(segment, high + 1);
	free (segment);
	return (x);
}
