/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inoteboo <inoteboo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:51:40 by inoteboo          #+#    #+#             */
/*   Updated: 2023/04/05 06:59:25 by inoteboo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort(int stack_a[], int stack_b[], int length);
void	qs_recursion_a(int stack_a[], int stack_b[], int high, int len[]);
void	qs_recursion_b(int stack_a[], int stack_b[], int high, int len[]);
int		three_sort_a(int stack_a[], int stack_b[], int len[]);
int		three_sort_b(int stack_a[], int stack_b[], int len[]);
int		a_sorted(int stack_a[], int length);
int		b_sorted(int stack_b[], int length);
void	swap_a(int stack_a[], int stack_b[]);
void	swap_b(int stack_a[], int stack_b[]);
void	swap_ab(int stack_a[], int stack_b[]);
int		rotate_a(int array[], int high);
int		rotate_b(int array[], int high);
int		two_sort_a(int stack_a[],int stack_b[]);
int		two_sort_b(int stack_a[], int stack_b[], int len[]);
void	push_to_a(int stack_a[], int stack_b[], int len[]);
void	push_to_b(int stack_a[], int stack_b[], int len[]);
int		reverse_rotate_b(int array[], int len);
int		reverse_rotate_a(int array[], int len);
int		pivot_finder(int array[], int high);
int		insertionsort(int segment[], int length);
int		ft_atoi(const char *str);
void	error(int stack_a[], int stack_b[], int which_one);

void	print(int stack_a[], int stack_b[], int len)
{
	int	x;

	x = 0;
	// return ;
	printf("\nA:");
	while (x < len)
	{
		printf("%d ", stack_a[x]);
		x++;
	}
	x = 0;
	printf("\nB:");
	while (x < len)
	{
		printf("%d ", stack_b[x]);
		x++;
	}
	printf("\n");
}

void	swap_a(int stack_a[], int stack_b[])
{
	// if (stack_b[0] < stack_b[1])
	// {
	// 	swap_ab(stack_a, stack_b);
	// 		return ;
	// }
	int	temp;

	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	write(1, "sa\n", 3);
}

void	swap_ab(int stack_a[], int stack_b[])
{
	int	temp;

	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	write(1, "ss\n", 3);
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

void	swap_b(int stack_a[], int stack_b[])
{
	// if (stack_a[0] > stack_a[1])
	// {
	// 	swap_ab(stack_a, stack_b);
	// 		return ;
	// }
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

int	two_sort_a(int stack_a[], int stack_b[])
{
	if (stack_a[0] > stack_a[1])
		swap_a(stack_a, stack_b);
	return (0);
}

int	two_sort_b(int stack_a[], int stack_b[], int len[])
{
	if (stack_b[0] < stack_b[1])
		swap_b(stack_a, stack_b);
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
		swap_a(stack_a, stack_b);
		push_to_a(stack_a, stack_b, len);
		if (a_sorted(stack_a, 3) == 1)
			return (0);
	}
	swap_a(stack_a, stack_b);
	if (a_sorted(stack_a, 3) == 1)
		return (0);
	push_to_b(stack_a, stack_b, len);
	swap_a(stack_a, stack_b);
	push_to_a(stack_a, stack_b, len);
	if (a_sorted(stack_a, 3) == 1)
		return (0);
	swap_a(stack_a, stack_b);
	return (0);
}

int	three_sort_b(int stack_a[], int stack_b[], int len[])
{
	int	count;

	count = 0;
	while (count < 3)
	{
		if (stack_a[0] > stack_a[1] && len[1] > 1)
			swap_a(stack_a, stack_b);
		if (stack_b[0] < stack_b[1] && count < 2)
			swap_b(stack_a, stack_b);
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

int rotate_check_b(int stack[], int p_val, int count, int high)
{
	int i;

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

int rotate_check_a(int stack[], int p_val, int count, int high)
{
	int i;

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

int	partition_a(int stack_a[], int stack_b[], int high, int len[])
{
	int	count;
	int	start_length;
	int	rotate_count;
	int	p_val;

	count = 0;
	start_length = len[1];
	rotate_count = 0;
	p_val = pivot_finder(stack_a, high);
	while (count <= high)
	{
		print(stack_a, stack_b, len[0]);
		if (stack_a[0] <= p_val)
			push_to_b(stack_a, stack_b, len);
		else if (count != high)
		{
			if (!rotate_check_a(stack_a, p_val, count, high))
				break;
			rotate_count += rotate_a(stack_a, (len[1] - 1));
		}
		count++;
	}
	while (rotate_count > 0 && (start_length - high) > 1)
		rotate_count -= reverse_rotate_a(stack_a, (len[1] - 1));
	print(stack_a, stack_b, len[0]);
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
	p_val = pivot_finder(stack_b, high);
	while (count <= high)
	{
		print(stack_a, stack_b, len[0]);
		if (stack_b[0] >= p_val)
			push_to_a(stack_a, stack_b, len);
		else if (count != high)
		{
			if (!rotate_check_b(stack_b, p_val, count, high))
				break;
			rotate_count += rotate_b(stack_b, len[0] - (len[1] + 1));
		}
		count++;
	}
	while (rotate_count > 0 && len[0] - start_length - high > 1)
		rotate_count -= reverse_rotate_b(stack_b, len[0] - (len[1] + 1));
	print(stack_a, stack_b, len[0]);
	return (len[1] - start_length);
}

void	qs_recursion_a(int stack_a[], int stack_b[], int high, int len[])
{
	int	p_index;

	if (high == 1)
		p_index = two_sort_a(stack_a, stack_b);
	if (high == 2)
		p_index = three_sort_a(stack_a, stack_b, len);
	print(stack_a, stack_b, high + 1);
	if (high > 2)
	{
		print(stack_a, stack_b, len[0]);
			p_index = partition_a(stack_a, stack_b, high, len);
		print(stack_a, stack_b, len[0]);
		qs_recursion_a(stack_a, stack_b, (p_index - 1), len);
		qs_recursion_b(stack_a, stack_b, (high - (p_index)), len);
	}
}

void	qs_recursion_b(int stack_a[], int stack_b[], int high, int len[])
{
	int	p_index;
	int x;
	
	x = 0;
	if (high == 0)
		push_to_a(stack_a, stack_b, len);
	if (high == 1)
		p_index = two_sort_b(stack_a, stack_b, len);
	if (high == 2)
		p_index = three_sort_b(stack_a, stack_b, len);
	if (high > 2)
	{
		print(stack_a, stack_b, len[0]);
		p_index = partition_b(stack_a, stack_b, high, len);
		print(stack_a, stack_b, len[0]);
		qs_recursion_a(stack_a, stack_b, (p_index - 1), len);
		qs_recursion_b(stack_a, stack_b, (high - (p_index)), len);
	}
}

int	pivot_finder(int array[], int high)
{
	int	x;
	int	*segment;

	segment = malloc(sizeof(int) * (high + 1));
	if (segment == NULL)
		return (0);
	x = 0;
	while (x <= high)
	{
		segment[x] = array[x];
		x++;
	}
	print(array, segment, high + 1);
	x = insertionsort(segment, high + 1);
	free (segment);
	return (x);
}

int	main(int argc, char *argv[])
{


	int	len[] = {15, 15};
	int	stack_a[] = {6, 0, 14, 10, 13, 5, 4, 7, 12, 9, 1, 11, 8, 15, 3};
	int	stack_b[15];

	// int	len[] = {100, 100};
	// int stack_a[] = {51, 42, 14, 10, 79, 97, 63, 11, 22, 91, 99, 39, 34, 16, 90, 49, 70, 92, 64, 61, 5, 4, 69, 35, 44, 15, 66, 46, 86, 78, 12, 55, 36, 23, 57, 38, 98, 83, 47, 32, 27, 53, 9, 17, 31, 20, 96, 8, 33, 59, 1, 18, 73, 71, 77, 52, 37, 75, 25, 81, 40, 80, 24, 30, 94, 19, 7, 41, 72, 68, 26, 88, 93, 3, 2, 50, 6, 67, 45, 54, 100, 48, 85, 58, 89, 95, 21, 62, 65, 60, 43, 87, 76, 82, 56, 13, 28, 74, 84, 29};
	// int stack_b[100];
	
	// int	len[] = {500, 500};
	// int stack_a[] = {102, 459, 240, 15, 211, 475, 104, 171, 483, 56, 72, 94, 233, 385, 27, 73, 18, 472, 281, 363, 136, 441, 159, 30, 13, 400, 352, 157, 395, 74, 252, 164, 129, 360, 199, 205, 398, 145, 316, 14, 186, 52, 197, 236, 265, 378, 303, 298, 286, 198, 445, 308, 456, 89, 5, 55, 158, 143, 98, 419, 44, 361, 306, 350, 116, 446, 4, 458, 262, 78, 24, 42, 135, 113, 187, 155, 429, 330, 305, 368, 432, 206, 150, 122, 362, 339, 32, 34, 463, 57, 85, 87, 328, 387, 254, 351, 222, 31, 49, 141, 263, 41, 238, 347, 332, 320, 120, 168, 310, 292, 139, 256, 388, 367, 154, 335, 133, 374, 329, 243, 287, 435, 93, 478, 180, 247, 365, 421, 193, 336, 412, 101, 2, 391, 413, 372, 245, 393, 25, 499, 409, 453, 270, 217, 384, 53, 132, 26, 444, 36, 276, 260, 210, 192, 203, 293, 331, 76, 396, 167, 327, 182, 106, 312, 344, 428, 173, 91, 268, 140, 244, 84, 438, 166, 337, 3, 359, 261, 369, 124, 99, 410, 37, 343, 285, 7, 235, 228, 105, 407, 279, 160, 494, 411, 496, 163, 97, 437, 313, 58, 246, 427, 142, 216, 371, 277, 22, 138, 81, 420, 80, 114, 392, 153, 304, 147, 448, 422, 214, 377, 79, 275, 430, 272, 301, 492, 258, 215, 184, 255, 64, 408, 314, 23, 63, 11, 289, 425, 223, 490, 112, 357, 185, 294, 38, 50, 195, 273, 474, 436, 196, 117, 297, 394, 376, 455, 318, 110, 390, 220, 307, 190, 500, 207, 349, 174, 403, 468, 29, 334, 62, 169, 249, 251, 434, 234, 92, 208, 389, 212, 48, 19, 282, 1, 225, 399, 302, 109, 144, 484, 452, 405, 479, 16, 75, 464, 82, 433, 417, 317, 402, 45, 423, 401, 242, 69, 442, 156, 172, 469, 274, 86, 426, 21, 485, 119, 71, 465, 218, 291, 123, 283, 280, 152, 364, 322, 383, 6, 51, 284, 257, 431, 370, 35, 65, 128, 165, 189, 460, 375, 342, 40, 43, 267, 134, 259, 311, 264, 10, 20, 380, 326, 416, 151, 204, 498, 229, 315, 209, 439, 269, 179, 341, 148, 67, 9, 266, 414, 17, 39, 299, 47, 230, 473, 177, 68, 70, 253, 191, 309, 355, 221, 137, 226, 379, 8, 356, 457, 224, 295, 493, 418, 333, 46, 188, 495, 486, 107, 466, 386, 338, 239, 462, 131, 219, 126, 60, 480, 200, 482, 130, 201, 149, 227, 443, 373, 146, 358, 451, 440, 404, 88, 54, 183, 232, 449, 181, 323, 178, 324, 366, 288, 447, 353, 231, 33, 118, 345, 96, 95, 125, 162, 103, 170, 406, 28, 127, 12, 487, 115, 83, 424, 415, 497, 237, 477, 382, 470, 471, 488, 194, 300, 454, 61, 161, 340, 321, 248, 290, 467, 271, 450, 66, 348, 213, 241, 176, 250, 481, 397, 278, 319, 491, 90, 108, 461, 202, 476, 175, 296, 346, 121, 381, 59, 489, 100, 77, 354, 325, 111};
	// int	stack_b[500];

	// int	len[] = {100, 100};
	// int stack_a[] = {59, 74, 54, 29, 20, 3, 72, 47, 35, 82, 30, 70, 69, 63, 44, 45, 91, 71, 5, 32, 26, 100, 8, 53, 28, 85, 57, 40, 89, 50, 68, 87, 37, 75, 41, 13, 21, 10, 95, 96, 92, 15, 83, 24, 43, 19, 16, 67, 73, 94, 62, 86, 51, 2, 61, 93, 64, 88, 39, 80, 31, 60, 42, 11, 9, 4, 76, 66, 79, 98, 90, 97, 56, 27, 55, 12, 7, 25, 1, 36, 23, 52, 99, 14, 77, 38, 46, 33, 84, 49, 17, 34, 78, 65, 48, 18, 58, 6, 81, 22};
	// int stack_b[100];

	// int stack_a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	// int stack_a[] = {9, 4, 47, 37, 32, 3, 13, 35, 30, 17, 41, 27, 19, 42, 31, 46, 44, 7, 23, 21, 38, 5, 12, 34, 10, 1, 24, 26, 6, 45, 40, 39, 28, 36, 8, 49, 15, 50, 11, 25, 48, 43, 22, 2, 14, 29, 33, 20, 18, 16};
	// int stack_a[] = {644, -113, -683, -325, -816, 717, 904, -942, 614, 306, -929, -217, -10, -576, 131, -673, -817, -719, -480, 302, 508, 706, 888, -194, 177, 787, 700, 161, 188, 236, 285, 895, 503, 517, 529, 253, -151, 691, -154, -707, -141, 28, 507, -721, -506, 163, 172, 747, -656, 666, 650, -239, -732, -304, -654, 291, -912, 113, -422, 238, 801, -86, -155, 357, 593, -183, 814, -21, 451, -75, 653, 280, 622, 966, 318, -205, -770, 547, 756, 427, 554, -403, -924, -674, 957, 449, -865, -881, -678, -271, 46, 699, -528, 141, -401, -438, 379, 909, -634, 945, 896, -915, -199, 275, -77, -36, -28, -454, 569, 581, 73, -208, -377, -116, -394, -360, 987, -612, 101, -285, -351, -758, 21, -846, -533, -783, -286, -450, -166, 295, -517, 746, -479, -672, -446, -641, 70, -572, 668, -306, 50, -482, 24, -258, -740, -222, -569, 712, -137, -385, 80, -211, -12, 990, -387, 687, -507, 697, -557, -815, -72, -763, -186, -784, -289, -432, 471, -715, 731, -500, 938, -456, 346, -257, 64, -149, -370, 210, -798, -527, -679, -402, 152, 538, -947, -637, -441, -262, 484, 200, -308, 34, 939, 158, 9, 912, 892, -73, -390, 512, 863, -575, 583, 634, -792, 187, 119, -509, -502, -588, 929, 877, 774, -447, -775, -241, 903, -282, -431, 47, -738, -599, 207, 62, -427, -681, 777, 32, -690, -173, 146, 129, -62, 388, -960, 657, -478, -235, 575, 365, 278, -940, -467, 418, -164, -536, -831, 678, 786, -975, 716, -162, 223, 4, -501, -437, -857, 942, 255, -558, -964, 193, 76, 744, 160, -412, -220, 168, 148, 515, -973, -710, 745, 35, -223, 519, 820, -233, -619, -203, 988, 726, -756, 525, 450, 915, 123, 681, -47, 202, -382, -18, 98, -687, 254, 159, 806, 135, -880, 983, 658, 481, -892, 378, -844, -269, -343, -684, 955, 425, -130, -914, 463, -604, -922, 312, -200, 310, -227, 930, -823, 572, 624, 239, -843, -93, -863, -40, 850, 288, -453, -284, 752, -494, -247, 180, 348, 854, -134, -841, 327, 136, 222, -358, 886, -296, -265, 680, -818, -407, -549, -361, -353, 947, 675, 479, -541, 637, 93, -85, -418, -956, -516, -288, -1000, -457, 993, -207, 881, 567, -850, -339, -908, 498, -626, 420, 265, 38, 79, 516, 760, -46, -952, -543, -677, -764, 940, 341, -658, -238, -583, 580, -751, 352, 125, -729, 96, -936, -135, -252, -294, -488, 735, -731, 725, -139, -801, -617, 485, 130, 876, 616, 837, 334, 20, -34, 44, 989, 464, 963, -31, 908, -305, -733, -231, 803, -114, -746, -819, 582, -984, -87, -769, 421, -795, 763, 677, 185, -191, -622, 165, 308, -983, -804, 539, -918, 604, -657, -293, -317, -937, 215, -544, 461, 770, -787, -470, 217, 831, -219, -270, 916, -253, 776, 454, -74, -602, 201, 669, 401, -794, 834, -355, 122, -99, 596, 171, -67, 342, 157, -505, 67, -410, -110, 43, 911, -663, 351, 696, -464, 812, 196, -78, 894, -772, 154, 720, -391, -276, -493};
	// int stack_a[] = {2, 1, 3, 4, 5, 8, 7, 6, 9, 10};
	// len = 500;
	quicksort(stack_a, stack_b, len[0]);
	print(stack_a, stack_b, len[0]);
	if (a_sorted(stack_a, len[0]) == 1)
		printf("sort OK\n");
	else
		printf("sort NOK\n");

	// int	i;
	// int	*stack_a;
	// int	*stack_b;

	// i = 0;
	// stack_a = malloc((sizeof(int)) * (argc - 1));
	// if (stack_a == NULL)
	// 	return (error(stack_a, stack_b, 0), -1);
	// stack_b = malloc((sizeof(int)) * (argc - 1));
	// if (stack_b == NULL)
	// 	return (error(stack_a, stack_b, 1), -1);
	// while (i < argc - 1)
	// {
	// 	if (!ft_atoi(argv[i + 1]))
	// 		return (error(stack_a, stack_b, 2), -1);
	// 	stack_a[i] = ft_atoi(argv[i + 1]);
	// 	i++;
	// }
	// quicksort(stack_a, stack_b, argc - 1);
	// free (stack_a);
	// free (stack_b);
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
	if (!(*str >= 48 && *str <= 57))
		return (0);
	if (i == 45)
		c = -c;
	return (c);
}

void	quicksort(int stack_a[], int stack_b[], int length)
{
	int	len[2];

	len[0] = length;
	len[1] = length;
	qs_recursion_a(stack_a, stack_b, len[0] - 1, len);
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
