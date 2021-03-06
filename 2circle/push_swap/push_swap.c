/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:44:11 by jislim            #+#    #+#             */
/*   Updated: 2022/06/05 23:48:40 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_int_data	*data;

	if (argc < 2)
		return (1);
	stack_a = create_linked_stack();
	if (!stack_a)
		return (1);
	data = create_int_data(MAX_SIZE);
	data = parsing(argv, data, 1, 0);
	put_on_stack_a(stack_a, data);
	if (stack_a->current_element_cnt == 1)
		return (0);
	check_dup(stack_a);
	check_sort(stack_a);
	stack_b = create_linked_stack();
	if (!stack_b)
		return (1);
	check_and_sort(stack_a, stack_b, data);
	delete_linked_stack(stack_a);
	delete_linked_stack(stack_b);
	return (0);
}
