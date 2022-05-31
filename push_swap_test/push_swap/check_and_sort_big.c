/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_sort_big.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:51:35 by jislim            #+#    #+#             */
/*   Updated: 2022/05/31 21:36:11 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_loose_sort(int *arr)
{
	int	check;
	int	idx;

	check = ascending;
	idx = 0;
	while (idx < 4)
	{
		if (arr[idx] < arr[idx + 1])
			check = 0;
		idx++;
	}
	if (check == 1)
		return (ascending);
	check = descending;
	idx = 0;
	while (idx < 4)
	{
		if (arr[idx] > arr[idx + 1])
			check = 0;
		idx++;
	}
	if (check == 2)
		return (descending);
	return (0);
}

int		get_average(int	*data, int start_range, int end_range)
{
	int	average;

	average = 0;
	while (start_range < end_range)
	{
		average += data[start_range];
		start_range++;
	}
	average /= end_range - start_range;
	return (average);
}

void	check_and_sort(t_stack *stack_a, t_stack *stack_b, t_int_data *data)
{
	int	arr[5];
	int	repeat; // 얘 만큼 반복. if 500
	int	idx;

	if (data->cnt <= 5)
		sort_big_number(stack_a, stack_b, data);
	repeat = (data->cnt) / 5; // 100
	printf("repeat : %d", repeat);
	idx = 0;
	while (idx < 5)
	{
		arr[idx] = get_average(data->arr, repeat * idx, repeat * (idx + 1));
		idx++;
	}
	if (check_loose_sort(data->arr) == 1 || check_loose_sort(data->arr) == 2)
		check_loose_sort(data->arr); // 그냥 넘기기
	else
		sort_big_number(stack_a, stack_b, data);
}

void	move_stack_a_to_stack_b_loose(t_stack *stack_a, t_stack *stack_b, t_int_data *data)
{
	if (stack_a && stack_b && data)
	{
		while (stack_a->current_element_cnt)
		{
			push_swap_pb(stack_a, stack_b);
		}
	}
}

void	sort_big_number(t_stack *stack_a, t_stack *stack_b, t_int_data *data)
{
	int	chunk;

	if (stack_a && stack_b && data)
	{
		if (data->cnt <= 5)
			less_than_or_equal_five(stack_a, stack_b);
		chunk = get_chunk(data);
		move_stack_a_to_stack_b(stack_a, stack_b, chunk);
		move_stack_b_to_stack_a(stack_a, stack_b);
	}
}
