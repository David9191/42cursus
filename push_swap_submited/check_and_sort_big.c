/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_sort_big.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:51:35 by jislim            #+#    #+#             */
/*   Updated: 2022/06/02 19:39:45 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_and_sort(t_stack *stack_a, t_stack *stack_b, t_int_data *data)
{
	if (stack_a && stack_b && data)
	{
		if (stack_a->current_element_cnt > 5 && check_descending(stack_a) == 1)
		{
			move_stack_a_to_stack_b_descen(stack_a, stack_b, data);
			move_stack_b_to_stack_a(stack_a, stack_b);
		}
		else
			sort_number(stack_a, stack_b, data);
	}
	else
		error_exit(0);
}

int	check_descending(t_stack *stack)
{
	t_stacknode	*node;
	t_stacknode	*next;

	if (stack)
	{
		node = stack->p_top_element;
		while (node->p_link)
		{
			next = node->p_link;
			if (node->data < next->data)
				return (0);
			node = next;
		}
		return (1);
	}
	else
		error_exit(0);
	return (0);
}

void	move_stack_a_to_stack_b_descen(t_stack *stack_a,
			t_stack *stack_b, t_int_data *data)
{
	if (stack_a && stack_b && data)
	{
		while (stack_a->current_element_cnt)
		{
			push_swap_pb(stack_a, stack_b);
		}
		free (data->arr);
		free (data);
	}
	else
		error_exit(0);
}

void	sort_number(t_stack *stack_a, t_stack *stack_b, t_int_data *data)
{
	int	chunk;
	int	check_min;

	if (stack_a && stack_b && data)
	{
		if (data->cnt <= 5)
			less_than_or_equal_five(stack_a, stack_b);
		chunk = get_chunk(data);
		check_min = check_where_min(stack_a);
		move_stack_a_to_stack_b(stack_a, stack_b, chunk, check_min);
		move_stack_b_to_stack_a(stack_a, stack_b);
		free (data->arr);
		free (data);
	}
	else
		error_exit(0);
}

int	get_chunk(t_int_data *data)
{
	if (data)
	{
		if (data->cnt == 100)
			return (15);
		else if (data->cnt == 500)
			return (30);
		else if (data->cnt > 500)
			return (45);
	}
	return (FALSE);
}
