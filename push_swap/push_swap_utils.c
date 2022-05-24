/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:44:18 by jislim            #+#    #+#             */
/*   Updated: 2022/05/24 20:30:18 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a) : Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
int	push_swap_sa(t_linked_satck *p_stack_a)
{
	t_stacknode	*temp;

	if (!p_stack_a || 2 > p_stack_a->current_element_cnt)
		return (0);
	temp = p_stack_a->p_top_element;
	p_stack_a->p_top_element = p_stack_a->p_top_element->p_link;
	temp->p_link = p_stack_a->p_top_element->p_link;
	p_stack_a->p_top_element->p_link = temp;
	return (1);
}

// sb (swap b) : Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
int	push_swap_sb(t_linked_satck *pStackB)
{
	t_stacknode	*temp;

	if (!pStackB || 2 > pStackB->current_element_cnt)
		return (0);
	temp = pStackB->p_top_element;
	pStackB->p_top_element = pStackB->p_top_element->p_link;
	temp->p_link = pStackB->p_top_element->p_link;
	pStackB->p_top_element->p_link = temp;
	return (1);
}

// pa (push a) : Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
int	push_swap_pa(t_linked_satck *p_stack_a, t_linked_satck *pStackB)
{
	t_stacknode	*node;
	int			check;

	if (!pStackB || 1 > pStackB->current_element_cnt)
		return (0);
	node = pop_linked_stack(pStackB);
	if (!node)
		return (0);
	check = push_linked_stack(p_stack_a, *node);
	// 여기서 free를 안해주면 메인에서 deleteStack해도 이미 node는 pStack에 포함되어 있지 않기 때문에
	// free를 못해줌.
	free (node);
	if (!check)
		return (0);
	return (1);
}

// pb (push b) : Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
int	push_swap_pb(t_linked_satck *p_stack_a, t_linked_satck *pStackB)
{
	t_stacknode	*node;
	int			check;

	if (!p_stack_a || 1 > p_stack_a->current_element_cnt)
		return (0);
	node = pop_linked_stack(p_stack_a);
	if (!node)
		return (0);
	check = push_linked_stack(pStackB, *node);
	free (node); // pop_linked_stack에서 free하면 이미 메모리 반환 후 이므로 쓰레기 값이 들어감.
	// free 했을 시 -> Process 12544: 0 leaks for 0 total leaked bytes.
	// free 안했을 시 -> Process 12416: 100 leaks for 1600 total leaked bytes.
	// 클러스터 맥에서 a push_swap.c push_swap_util* ./libft/*.c -g3 -fsanitize=address 해보기
	if (!check)
		return (0);
	return (1);
}

// ra (rotate a) : Shift up all elements of stack a by 1.
// The first element becomes the last one.
int	push_swap_ra(t_linked_satck *p_stack_a)
{
	t_stacknode	*top;
	t_stacknode	*bottom;

	if (!p_stack_a || 2 > p_stack_a->current_element_cnt)
		return (0);
	top = p_stack_a->p_top_element;
	// top을 1인덱스로 바꾸는 작업
	p_stack_a->p_top_element = p_stack_a->p_top_element->p_link;
	bottom = top;
	while (bottom->p_link)
		bottom = bottom->p_link;
	bottom->p_link = top;
	top->p_link = NULL;
	return (1);
}

// rb (rotate b) : Shift up all elements of stack b by 1.
// The first element becomes the last one.
int	push_swap_rb(t_linked_satck *pStackB)
{
	t_stacknode	*top;
	t_stacknode	*bottom;

	if (!pStackB || 2 > pStackB->current_element_cnt)
		return (0);
	top = pStackB->p_top_element;
	// top을 1인덱스로 바꾸는 작업
	pStackB->p_top_element = pStackB->p_top_element->p_link;
	bottom = top;
	while (bottom->p_link)
		bottom = bottom->p_link;
	bottom->p_link = top;
	top->p_link = NULL;
	return (1);
}

// rra (reverse rotate a) : Shift down all elements of stack a by 1.
// The last element becomes the first one.
int	push_swap_rra(t_linked_satck *p_stack_a)
{
	t_stacknode	*top;
	t_stacknode	*pre_bottom;
	t_stacknode	*bottom;

	if (!p_stack_a || 2 > p_stack_a->current_element_cnt)
		return (0);
	top = p_stack_a->p_top_element;
	bottom = top;
	while (bottom->p_link)
	{
		pre_bottom = bottom;
		bottom = bottom->p_link;
	}
	pre_bottom->p_link = NULL;
	p_stack_a->p_top_element = bottom;
	bottom->p_link = top;
	return (1);
}

// rrb (reverse rotate b) : Shift down all elements of stack b by 1.
// The last element becomes the first one.
int	push_swap_rrb(t_linked_satck *pStackB)
{
	t_stacknode	*top;
	t_stacknode	*pre_bottom;
	t_stacknode	*bottom;

	if (!pStackB || 2 > pStackB->current_element_cnt)
		return (0);
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
	return (1);
}
