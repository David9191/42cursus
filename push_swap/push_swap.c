/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:44:11 by jislim            #+#    #+#             */
/*   Updated: 2022/05/27 20:43:38 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_linked_satck	*stack_a = create_linked_stack();

	if (argc < 2)
		return (1);
	parsing(argv, stack_a);
	// 중복 체크 -> 정렬체크 -> indexing
	t_stacknode	*node = stack_a->p_top_element;
	while (node)
	{
		printf("%d\n", node->data);
		node = node->p_link;
	}

	delete_linked_stack(stack_a);
	system("leaks push_swap | grep leaked");
	return (0);
}

// push_swap

// 3 ~ 5개는 하드코딩.
// 3개는 B를 만들지도 않고 A에서 다 작업.
// 4개는 제일 큰 값을 B로 넘기고 -> 3개 함수 부르기 -> B to A 하나씩 해주기.
// 4개는 제일 큰 값 2개를 B로 넘기고 -> 3개 함수 부르기 -> B to A 하나씩 해주기.

// 로직 설명 -> 수식 설명.
