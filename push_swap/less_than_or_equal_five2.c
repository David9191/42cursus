/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_or_equal_five2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:35:18 by jislim            #+#    #+#             */
/*   Updated: 2022/05/30 18:02:37 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_case_three(t_stack *stack_a, int first, int second, int third)
{
	if (stack_a)
	{
		if (first > second && second > third)
		{
			push_swap_sa(stack_a);
			push_swap_rra(stack_a);
		}
		else if (first < second && second > third && first < third)
		{
			push_swap_rra(stack_a);
			push_swap_sa(stack_a);
		}
		else if (first < second && second > third && first > third)
			push_swap_rra(stack_a);
		else if (first > second && second < third && first < third)
			push_swap_sa(stack_a);
		else if (first > second && second < third && first > third)
			push_swap_ra(stack_a);
		return (TRUE);
	}
	error_exit(0);
	return (FALSE);
}

int	find_min(t_stack *stack_a)
{
	t_stacknode	*node;
	int			min;

	if (stack_a)
	{
		min = stack_a->p_top_element->data;
		node = stack_a->p_top_element->p_link;
		while (node)
		{
			if (min > node->data)
				min = node->data;
			node = node->p_link;
		}
		return (min);
	}
	error_exit(0);
	return (FALSE);
}
