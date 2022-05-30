/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_big.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:05:25 by jislim            #+#    #+#             */
/*   Updated: 2022/05/30 18:12:00 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_number(t_stack *stack_a, t_stack *stack_b, t_int_data *data)
{
	int	chunk;

	if (stack_a && stack_b && data)
	{
		if (data->cnt <= 5)
			less_than_or_equal_five(stack_a, stack_b);
		chunk = get_chunk(data);
		move_stack_a_to_stack_b(stack_a, stack_b, chunk);
		move_stack_b_to_stack_a(stack_a, stack_b);
	}
}
