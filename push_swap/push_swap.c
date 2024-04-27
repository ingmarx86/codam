/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:51:40 by inoteboo          #+#    #+#             */
/*   Updated: 2023/04/04 14:09:04 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	*stack_a;
	int	*stack_b;

	i = 0;
	stack_a = malloc((sizeof(int)) * (argc - 1));
	if (stack_a == NULL)
		return (error(stack_a, stack_a, 0), -1);
	stack_b = malloc((sizeof(int)) * (argc - 1));
	if (stack_b == NULL)
		return (error(stack_a, stack_b, 1), -1);
	while (i < argc - 1)
	{
		if (!ft_atoi(argv[i + 1]))
			return (error(stack_a, stack_b, 2), -1);
		stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (quicksort(stack_a, stack_b, argc - 1) == -1)
		return (-1);
	free (stack_a);
	free (stack_b);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	long long int	c;

	i = 0;
	c = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
	str++;
	if (!((*str >= 48 && *str <= 57) || *str == '-' || *str == '+'))
		return (0);
	if (*str == '-' || *str == '+')
	{
		i = *str;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		c = (c * 10) + (*str - 48);
		str++;
	}
	if (i == 45)
		c = -c;
	if (c > INT32_MAX || c < INT32_MIN || *str != '\0')
		return (0);
	return (c);
}

int	quicksort(int stack_a[], int stack_b[], int length)
{
	int	len[2];

	len[0] = length;
	len[1] = length;
	if (!dup_check(stack_a, len[0]))
		return (error(stack_a, stack_b, 2), -1);
	if ((length == 3 || length == 5) && !a_sorted(stack_a, length))
		small_sort(stack_a, stack_b, len);
	qs_recursion_a(stack_a, stack_b, len[0] - 1, len);
	return (0);
}

void	error(int stack_a[], int stack_b[], int which_one)
{
	write(2, "Error\n", 6);
	if (which_one == 0)
		return ;
	free (stack_a);
	if (which_one == 2)
		free (stack_b);
	return ;
}

void	small_sort(int stack_a[], int stack_b[], int len[])
{
	int	i;

	i = 0;
	if (stack_a[0] < stack_a[1] && len[0] == 3)
		reverse_rotate_a(stack_a, len[0] - 1);
	if (stack_a[0] < stack_a[2] && !a_sorted(stack_a, len[0]) && len[0] == 3)
		swap_a(stack_a);
	if (!a_sorted(stack_a, len[0]) && len[0] == 3)
		rotate_a(stack_a, len[0] - 1);
	if (!a_sorted(stack_a, len[0]) && len[0] == 3)
		swap_a(stack_a);
	while (len[0] == 5 && i < 5 && stack_a[i] > stack_a[i + 1])
		i++;
	if (i == 4)
	{
		reverse_rotate_a(stack_a, len[1] - 1);
		push_to_b(stack_a, stack_b, len);
		swap_a(stack_a);
		rotate_a(stack_a, len[1] - 1);
		rotate_a(stack_a, len[1] - 1);
		swap_a(stack_a);
		push_to_a(stack_a, stack_b, len);
	}
}
