/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_sort_big.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:51:35 by jislim            #+#    #+#             */
/*   Updated: 2022/06/01 22:02:52 by jislim           ###   ########.fr       */
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

	if (stack_a && stack_b && data)
	{
		if (data->cnt <= 5)
			less_than_or_equal_five(stack_a, stack_b);
		chunk = get_chunk(data);
		free (data->arr);
		free (data);
		move_stack_a_to_stack_b(stack_a, stack_b, chunk);
		move_stack_b_to_stack_a(stack_a, stack_b);
	}
	else
		error_exit(0);
}
