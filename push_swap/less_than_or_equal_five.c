/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_or_equal_five.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:34:54 by jislim            #+#    #+#             */
/*   Updated: 2022/06/02 11:58:50 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_is_top(t_stack *stack_a, int min)
{
	t_stacknode	*node;
	int			half;

	if (!stack_a)
		error_exit(0);
	node = stack_a->p_top_element;
	half = (stack_a->current_element_cnt) / 2;
	while (half--)
	{
		if (min == node->data)
			return (TRUE);
		node = node->p_link;
	}
	return (FALSE);
}

int	min_to_stack_b(t_stack *stack_a,
	t_stack *stack_b)
{
	int	idx;
	int	min;

	if (!stack_a || !stack_b)
		error_exit(0);
	idx = 0;
	if (stack_a->p_top_element != NULL)
	{
		min = find_min(stack_a);
		if (min_is_top(stack_a, min))
			while (min != stack_a->p_top_element->data)
				push_swap_ra(stack_a);
		else
			while (min != stack_a->p_top_element->data)
				push_swap_rra(stack_a);
		push_swap_pb(stack_a, stack_b);
	}
	return (TRUE);
}

int	in_case_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	if (stack_a && stack_b)
	{
		min = min_to_stack_b(stack_a, stack_b);
		in_case_three(stack_a, stack_a->p_top_element->data, \
				stack_a->p_top_element->p_link->data, \
				stack_a->p_top_element->p_link->p_link->data);
		push_swap_pa(stack_a, stack_b);
		return (TRUE);
	}
	error_exit(0);
	return (FALSE);
}

int	in_case_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	if (stack_a && stack_b)
	{
		min = min_to_stack_b(stack_a, stack_b);
		min = min_to_stack_b(stack_a, stack_b);
		in_case_three(stack_a, stack_a->p_top_element->data, \
				stack_a->p_top_element->p_link->data, \
				stack_a->p_top_element->p_link->p_link->data);
		push_swap_pa(stack_a, stack_b);
		push_swap_pa(stack_a, stack_b);
		return (TRUE);
	}
	error_exit(0);
	return (FALSE);
}

int	less_than_or_equal_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_b)
	{
		if (stack_a->current_element_cnt == 2)
			push_swap_sa(stack_a);
		else if (stack_a->current_element_cnt == 3)
			in_case_three(stack_a, stack_a->p_top_element->data,
				stack_a->p_top_element->p_link->data,
				stack_a->p_top_element->p_link->p_link->data);
		else if (stack_a->current_element_cnt == 4)
			in_case_four(stack_a, stack_b);
		else if (stack_a->current_element_cnt == 5)
			in_case_five(stack_a, stack_b);
	}
	error_exit(0);
	return (FALSE);
}
