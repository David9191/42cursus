/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:39:51 by jislim            #+#    #+#             */
/*   Updated: 2022/06/02 19:52:03 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_where_min(t_stack	*stack_a)
{
	t_stacknode	*node;
	int			idx;
	int			top;
	int			half;

	node = stack_a->p_top_element;
	idx = 0;
	top = 0;
	half = (stack_a->current_element_cnt) / 2;
	while (idx < half)
	{
		if (node->index < (stack_a->current_element_cnt) / 2)
			top++;
		idx++;
		node = node->p_link;
	}
	if (top > half)
		return (IN_TOP);
	else
		return (IN_BOTTOM);
}

int	move_stack_a_to_stack_b(t_stack *stack_a,
	t_stack *stack_b, int chunk, int check_min)
{
	int	num;
	int	index;

	num = 0;
	while (stack_a->current_element_cnt)
	{
		index = stack_a->p_top_element->index;
		if (num >= index)
		{
			push_swap_pb(stack_a, stack_b);
			num++;
		}
		else if (num < index && index <= num + chunk)
		{
			push_swap_pb(stack_a, stack_b);
			push_swap_rb(stack_b);
			num++;
		}
		else if (num + chunk < index && check_min == IN_TOP)
			push_swap_ra(stack_a);
		else if (num + chunk < index && check_min == IN_BOTTOM)
			push_swap_rra(stack_a);
	}
	return (1);
}

int	max_is_top(t_stack *stack_b)
{
	t_stacknode	*node;
	int			half;
	int			max;

	if (!stack_b)
		error_exit(0);
	node = stack_b->p_top_element;
	half = (stack_b->current_element_cnt) / 2;
	max = (stack_b->current_element_cnt) - 1;
	while (half--)
	{
		if (max == node->index)
			return (TRUE);
		node = node->p_link;
	}
	return (FALSE);
}

int	move_stack_b_to_stack_a(t_stack *stack_a,
	t_stack *stack_b)
{
	int	idx;
	int	max;

	if (!stack_a || !stack_b)
		error_exit(0);
	idx = 0;
	while (stack_b->p_top_element != NULL)
	{
		max = (stack_b->current_element_cnt) - 1;
		if (max_is_top(stack_b))
			while (max != stack_b->p_top_element->index)
				push_swap_rb(stack_b);
		else
			while (max != stack_b->p_top_element->index)
				push_swap_rrb(stack_b);
		push_swap_pa(stack_a, stack_b);
	}
	return (TRUE);
}

t_int_data	*create_int_data(int max_cnt)
{
	t_int_data	*rt_int_data;

	rt_int_data = NULL;
	if (max_cnt > 0)
	{
		rt_int_data = malloc(sizeof(t_int_data));
		if (!rt_int_data)
			error_exit(0);
		rt_int_data->arr = malloc(sizeof(int) * max_cnt);
		if (!rt_int_data->arr)
			error_exit(0);
		rt_int_data->cnt = 0;
		return (rt_int_data);
	}
	error_exit(0);
	return (rt_int_data);
}
