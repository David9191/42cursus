/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkedstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:44:48 by jislim            #+#    #+#             */
/*   Updated: 2022/05/28 14:04:24 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_linked_satck	*create_linked_stack(void)
{
	t_linked_satck	*rt_satck;

	rt_satck = malloc(sizeof(t_linked_satck));
	if (!rt_satck)
		return (NULL);
	rt_satck->current_element_cnt = 0;
	rt_satck->p_top_element = NULL;
	return (rt_satck);
}

int	push_linked_stack(t_linked_satck *pStack, t_stacknode element)
{
	t_stacknode	*node;

	if (!pStack)
		return (FALSE);
	node = malloc(sizeof(t_stacknode));
	if (!node)
		return (FALSE);
	*node = element;
	node->p_link = pStack->p_top_element;
	pStack->p_top_element = node;
	pStack->current_element_cnt += 1;
	return (TRUE);
}

t_stacknode	*pop_linked_stack(t_linked_satck *stack)
{
	t_stacknode	*rt_node;

	if (!stack || !(stack->current_element_cnt))
		return (FALSE);
	rt_node = stack->p_top_element;
	stack->p_top_element = stack->p_top_element->p_link;
	stack->current_element_cnt -= 1;
	return (rt_node);
}

t_stacknode	*peek_linked_stack(t_linked_satck *stack)
{
	if (!stack || !(stack->current_element_cnt))
		return (FALSE);
	return (stack->p_top_element);
}

void	delete_linked_stack(t_linked_satck *stack)
{
	t_stacknode	*del;
	t_stacknode	*next;

	if (!stack || !(stack->p_top_element))
	{
		free (stack);
		return ;
	}
	del = stack->p_top_element;
	next = del;
	while (del)
	{
		next = del->p_link;
		free(del);
		del = next;
	}
	free (stack);
}
