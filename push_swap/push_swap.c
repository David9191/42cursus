/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:44:11 by jislim            #+#    #+#             */
/*   Updated: 2022/05/25 21:26:06 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_linked_satck	*p_stack_a;
	t_linked_satck	*p_stack_b;
	t_stacknode		*node_a;
	int				num;
	int				chunk;
	int				*arr;

	ft_printf("argc : %d\n", argc - 1);
	if (argc < 2)
		return (0);
	num = 0;
	chunk = 15;
	if (argc - 1 == 500)
		chunk = 30;
	arr = parsing(argc - 1, argv);
	p_stack_a = create_p_stack_a(arr, argc - 1);
	node_a = p_stack_a->p_top_element;
	for (int i = 0; i < argc - 1; i++)
	{
		int d = node_a->index;
		ft_printf("%3d : ", d);
		while (d--)
			ft_printf(".");
		ft_printf("\n");
		node_a = node_a->p_link;
	}
	// t_stacknode	*node_a = p_stack_a->p_top_element;
	// while (node_a)
	// {
	// 	printf("index : %d\n", node_a->index);
	// 	node_a = node_a->p_link;
	// }
	ft_printf("\nA crnt cnt : %d\n", p_stack_a->current_element_cnt);
	p_stack_b = create_linked_stack();
	move_p_stack_a_to_p_stack_b(p_stack_a, p_stack_b, 15);
	ft_printf("\nB crnt cnt : %d\n", p_stack_b->current_element_cnt);
	t_stacknode *node_b = p_stack_b->p_top_element;
	for (int i = 0; i < argc - 1; i++)
	{
		int d = node_b->index;
		// ft_printf("%d : ", d);
		while (d--)
			ft_printf(".");
		ft_printf("\n");
		node_b = node_b->p_link;
	}
	// while (node_b)
	// {
	// 	printf("index : %d\n", node_b->index);
	// 	node_b = node_b->p_link;
	// }
	ft_printf("\n\n");
	move_p_stack_b_to_p_stack_a(p_stack_a, p_stack_b);
	node_a = p_stack_a->p_top_element;
	for (int i = 0; i < argc - 1; i++)
	{
		int d = node_a->index;
		// ft_printf("%d : ", d);
		while (d--)
			ft_printf(".");
		ft_printf("\n");
		node_a = node_a->p_link;
	}
	delete_linked_stack(p_stack_a);
	delete_linked_stack(p_stack_b);
	system("leaks push_swap | grep leaked");
	return (0);
}

// push_swap

// 3 ~ 5개는 하드코딩.
// 3개는 B를 만들지도 않고 A에서 다 작업.
// 4개는 제일 큰 값을 B로 넘기고 -> 3개 함수 부르기 -> B to A 하나씩 해주기.
// 4개는 제일 큰 값 2개를 B로 넘기고 -> 3개 함수 부르기 -> B to A 하나씩 해주기.

// 로직 설명 -> 수식 설명.
