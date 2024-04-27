/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 09:42:52 by inoteboo          #+#    #+#             */
/*   Updated: 2023/04/04 08:15:46 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(int stack_b[])
{
	int	temp;

	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	write(1, "sb\n", 3);
}

int	rotate_b(int array[], int high)
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
	write(1, "rb\n", 3);
	return (1);
}

int	reverse_rotate_b(int array[], int len)
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
	array[0] = temp;
	write(1, "rrb\n", 4);
	return (1);
}

void	push_to_b(int stack_a[], int stack_b[], int len[])
{	
	int	i;

	i = 0;
	if (stack_a[0] == 0)
		return ;
	while (i < len[0] - 1)
	{
		stack_b[len[0] - (i + 1)] = stack_b[len[0] - (i + 2)];
		i++;
	}
	stack_b[0] = stack_a[0];
	len[1] -= 1;
	i = 0;
	while (i < (len[0] - 1))
	{
	stack_a[i] = stack_a[i + 1];
		i++;
	}
	write(1, "pb\n", 3);
}

int	b_sorted(int stack_b[], int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (stack_b[i] > stack_b[i + 1])
		i++;
		else
			return (0);
	}
	return (1);
}
