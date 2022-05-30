/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:44:11 by jislim            #+#    #+#             */
/*   Updated: 2022/05/30 16:29:15 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_linked_satck	*stack_a;
	t_linked_satck	*stack_b;
	t_int_data		*data;
	int				chunk;

	if (argc < 2)
		return (1);
	stack_a = create_linked_stack();
	stack_b = create_linked_stack();
	if (!stack_a || !stack_b)
		return (1);
	data = create_int_data(500);
	parsing(argv, data);
	put_on_stack_a(stack_a, data);
	if (stack_a->current_element_cnt == 1)
		return (0);
	check_dup(stack_a);
	check_sort(stack_a);
	if (data->cnt <= 5)
		less_than_or_equal_five(stack_a, stack_b);
	chunk = get_chunk(data);
	move_p_stack_a_to_p_stack_b(stack_a, stack_b, chunk);
	move_p_stack_b_to_p_stack_a(stack_a, stack_b);
	delete_linked_stack(stack_a);
	delete_linked_stack(stack_b);
	// system("leaks push_swap | grep leaked");
	return (0);
}

// push_swap

// 3 ~ 5개는 하드코딩.
// 3개는 B를 만들지도 않고 A에서 다 작업.
// 4개는 제일 큰 값을 B로 넘기고 -> 3개 함수 부르기 -> B to A 하나씩 해주기.
// 4개는 제일 큰 값 2개를 B로 넘기고 -> 3개 함수 부르기 -> B to A 하나씩 해주기.

// 로직 설명 -> 수식 설명.

	// t_stacknode	*node = stack_a->p_top_element;
	// while (node)
	// {
	// 	printf("%d ",  node->data);
	// 	node = node->p_link;
	// }
	// printf("\n");
	// node = stack_a->p_top_element;
	// while (node)
	// {
	// 	printf("%d ",  node->index);
	// 	node = node->p_link;
	// }
	// printf("\n");
	// node = stack_a->p_top_element;
	// // p_stack_a_indexing(stack_a);
	// while (node)
	// {
	// 	printf("%d ",  node->index);
	// 	node = node->p_link;
	// }
	// printf("\n");
