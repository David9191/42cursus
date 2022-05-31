/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_r_rr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:37:15 by jislim            #+#    #+#             */
/*   Updated: 2022/05/31 20:26:45 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_ra(t_stack *stack_a)
{
	t_stacknode	*top;
	t_stacknode	*bottom;

	if (!stack_a || 2 > stack_a->current_element_cnt)
		return (FALSE);
	top = stack_a->p_top_element;
	stack_a->p_top_element = stack_a->p_top_element->p_link;
	bottom = top;
	while (bottom->p_link)
		bottom = bottom->p_link;
	bottom->p_link = top;
	top->p_link = NULL;
	// write(1, "ra\n", 3);
	return (TRUE);
}

int	push_swap_rb(t_stack *pStackB)
{
	t_stacknode	*top;
	t_stacknode	*bottom;

	if (!pStackB || 2 > pStackB->current_element_cnt)
		return (FALSE);
	top = pStackB->p_top_element;
	pStackB->p_top_element = pStackB->p_top_element->p_link;
	bottom = top;
	while (bottom->p_link)
		bottom = bottom->p_link;
	bottom->p_link = top;
	top->p_link = NULL;
	// write(1, "rb\n", 3);
	return (TRUE);
}

int	push_swap_rra(t_stack *stack_a)
{
	t_stacknode	*top;
	t_stacknode	*pre_bottom;
	t_stacknode	*bottom;

	if (!stack_a || 2 > stack_a->current_element_cnt)
		return (FALSE);
	top = stack_a->p_top_element;
	bottom = top;
	while (bottom->p_link)
	{
		pre_bottom = bottom;
		bottom = bottom->p_link;
	}
	pre_bottom->p_link = NULL;
	stack_a->p_top_element = bottom;
	bottom->p_link = top;
	// write(1, "rra\n", 4);
	return (TRUE);
}

int	push_swap_rrb(t_stack *pStackB)
{
	t_stacknode	*top;
	t_stacknode	*pre_bottom;
	t_stacknode	*bottom;

	if (!pStackB || 2 > pStackB->current_element_cnt)
		return (FALSE);
	top = pStackB->p_top_element;
	bottom = top;
	while (bottom->p_link)
	{
		pre_bottom = bottom;
		bottom = bottom->p_link;
	}
	pre_bottom->p_link = NULL;
	pStackB->p_top_element = bottom;
	bottom->p_link = top;
	// write(1, "rrb\n", 4);
	return (TRUE);
}
