/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_s_p.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:36:47 by jislim            #+#    #+#             */
/*   Updated: 2022/06/02 11:59:08 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_sa(t_stack *stack_a)
{
	t_stacknode	*temp;

	if (!stack_a || 2 > stack_a->current_element_cnt)
		return (FALSE);
	temp = stack_a->p_top_element;
	stack_a->p_top_element = stack_a->p_top_element->p_link;
	temp->p_link = stack_a->p_top_element->p_link;
	stack_a->p_top_element->p_link = temp;
	write(1, "sa\n", 3);
	return (TRUE);
}

int	push_swap_sb(t_stack *pStackB)
{
	t_stacknode	*temp;

	if (!pStackB || 2 > pStackB->current_element_cnt)
		return (FALSE);
	temp = pStackB->p_top_element;
	pStackB->p_top_element = pStackB->p_top_element->p_link;
	temp->p_link = pStackB->p_top_element->p_link;
	pStackB->p_top_element->p_link = temp;
	write(1, "sb\n", 3);
	return (TRUE);
}

int	push_swap_pa(t_stack *stack_a, t_stack *pStackB)
{
	t_stacknode	*node;
	int			check;

	if (!pStackB || 1 > pStackB->current_element_cnt)
		return (FALSE);
	node = pop_linked_stack(pStackB);
	if (!node)
		return (FALSE);
	check = push_linked_stack(stack_a, *node);
	free (node);
	if (!check)
		return (FALSE);
	write(1, "pa\n", 3);
	return (TRUE);
}

int	push_swap_pb(t_stack *stack_a, t_stack *pStackB)
{
	t_stacknode	*node;
	int			check;

	if (!stack_a || 1 > stack_a->current_element_cnt)
		return (FALSE);
	node = pop_linked_stack(stack_a);
	if (!node)
		return (FALSE);
	check = push_linked_stack(pStackB, *node);
	free (node);
	if (!check)
		return (FALSE);
	write(1, "pb\n", 3);
	return (TRUE);
}
