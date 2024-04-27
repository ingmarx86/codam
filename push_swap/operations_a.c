/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 09:42:52 by inoteboo          #+#    #+#             */
/*   Updated: 2023/04/04 08:15:38 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int stack_a[])
{
	int	temp;

	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	write(1, "sa\n", 3);
}

int	rotate_a(int array[], int high)
{
	int	temp;
	int	i;

	temp = array[0];
	i = 0;
	while (i < high)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[high] = temp;
	write(1, "ra\n", 3);
	return (1);
}

int	reverse_rotate_a(int array[], int len)
{
	int	temp;
	int	i;

	temp = array[len];
	i = 0;
	while (i < len)
	{
		array[len] = array[len - 1];
		len--;
	}
	array[len] = temp;
	write(1, "rra\n", 4);
	return (1);
}

void	push_to_a(int stack_a[], int stack_b[], int len[])
{
	int	i;

	i = 0;
	if (stack_b[0] == 0)
		return ;
	while (i < len[0] - 1)
	{
	stack_a[len[0] - (i + 1)] = stack_a[len[0] - (i + 2)];
		i++;
	}
	stack_a[0] = stack_b[0];
	i = 0;
	while (i < (len[0] - 1))
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	len[1] += 1;
	write(1, "pa\n", 3);
}

int	a_sorted(int stack_a[], int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (stack_a[i] < stack_a[i + 1])
		i++;
		else
			return (0);
	}
	return (1);
}
