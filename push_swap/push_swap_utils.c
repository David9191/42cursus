/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:39:51 by jislim            #+#    #+#             */
/*   Updated: 2022/06/03 09:40:55 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_stack_a_to_stack_b(t_stack *stack_a,
	t_stack *stack_b, int chunk, int check_min)
{
	int	num;
	int	index;

	num = 0;
	while (stack_a->current_element_cnt)
	{
		index = stack_a->p_top_element->index;
		if (num >= index)
		{
			push_swap_pb(stack_a, stack_b);
			num++;
		}
		else if (num < index && index <= num + chunk)
		{
			push_swap_pb(stack_a, stack_b);
			push_swap_rb(stack_b);
			num++;
		}
		else if (num + chunk < index && check_min == NOT_WORST)
			push_swap_ra(stack_a);
		else if (num + chunk < index && check_min == WORST)
			push_swap_rra(stack_a);
	}
	return (1);
}

int	max_is_top(t_stack *stack_b)
{
	t_stacknode	*node;
	int			half;
	int			max;

	if (!stack_b)
		error_exit(0);
	node = stack_b->p_top_element;
	half = (stack_b->current_element_cnt) / 2;
	max = (stack_b->current_element_cnt) - 1;
	while (half--)
	{
		if (max == node->index)
			return (TRUE);
		node = node->p_link;
	}
	return (FALSE);
}

int	move_stack_b_to_stack_a(t_stack *stack_a,
	t_stack *stack_b)
{
	int	idx;
	int	max;

	if (!stack_a || !stack_b)
		error_exit(0);
	idx = 0;
	while (stack_b->p_top_element != NULL)
	{
		max = (stack_b->current_element_cnt) - 1;
		if (max_is_top(stack_b))
			while (max != stack_b->p_top_element->index)
				push_swap_rb(stack_b);
		else
			while (max != stack_b->p_top_element->index)
				push_swap_rrb(stack_b);
		push_swap_pa(stack_a, stack_b);
	}
	return (TRUE);
}

t_int_data	*create_int_data(int max_cnt)
{
	t_int_data	*rt_int_data;

	rt_int_data = NULL;
	if (max_cnt > 0)
	{
		rt_int_data = malloc(sizeof(t_int_data));
		if (!rt_int_data)
			error_exit(0);
		rt_int_data->arr = malloc(sizeof(int) * max_cnt);
		if (!rt_int_data->arr)
			error_exit(0);
		rt_int_data->cnt = 0;
		rt_int_data->size = max_cnt;
		return (rt_int_data);
	}
	error_exit(0);
	return (rt_int_data);
}

t_int_data	*copy_int_data(t_int_data *src, int max_cnt)
{
	t_int_data	*rt_int_data;

	rt_int_data = NULL;
	if (src && max_cnt > 0)
	{
		rt_int_data = malloc(sizeof(t_int_data));
		if (!rt_int_data)
			error_exit(0);
		rt_int_data->arr = malloc(sizeof(int) * max_cnt);
		if (!rt_int_data->arr)
			error_exit(0);
		ft_memcpy(rt_int_data->arr, src->arr, sizeof(int) * src->cnt);
		rt_int_data->cnt = src->cnt;
		rt_int_data->size = max_cnt;
		free (src);
		return (rt_int_data);
	}
	error_exit(0);
	return (rt_int_data);
}
