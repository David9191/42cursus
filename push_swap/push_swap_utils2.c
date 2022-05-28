/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:19:11 by jislim            #+#    #+#             */
/*   Updated: 2022/05/28 14:10:40 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_free_all(char **str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		free (str[idx]);
		idx++;
	}
	free (str);
}

void	parsing(char **argv, t_int_data *data)
{
	char		**str;
	int			i;
	int			j;
	int			k;

	i = 1;
	k = 0;
	while (argv[i])
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		while (str[j])
		{
			data->arr[k] = ft_atoi_push(str[j]);
			(data->cnt)++;
			k++;
			j++;
		}
		i++;
		split_free_all(str);
	}
}

void	put_on_stack_a(t_linked_satck *stack, t_int_data *data)
{
	t_stacknode	node;
	int			iter;

	if (stack && data)
	{
		iter = (data->cnt) - 1;
		while (iter >= 0)
		{
			node.data = data->arr[iter];
			node.index = iter;
			push_linked_stack(stack, node);
			p_stack_a_indexing(stack);
			iter--;
		}
		return ;
	}
	error_exit(0);
}

int	p_stack_a_indexing(t_linked_satck *p_stack_a)
{
	t_stacknode	*node;
	t_stacknode	*next;

	if (!p_stack_a)
		return (FALSE);
	node = p_stack_a->p_top_element;
	next = node;
	while (next)
	{
		if (node->data > next->data)
		{
			node->index++;
			next->index--;
		}
		next = next->p_link;
	}
	return (TRUE);
}

int	move_p_stack_a_to_p_stack_b(t_linked_satck *p_stack_a,
	t_linked_satck *p_stack_b, int chunk)
{
	t_stacknode	node;
	int			num;
	int			index;

	num = 0;
	while (p_stack_a->current_element_cnt)
	{
		index = p_stack_a->p_top_element->index;
		node.index = index;
		if (index <= num)
		{
			push_swap_pb(p_stack_a, p_stack_b);
			num++;
		}
		else if (num < index && index <= num + chunk)
		{
			push_swap_pb(p_stack_a, p_stack_b);
			push_swap_rb(p_stack_b);
			num++;
		}
		else if (index > num + chunk)
			push_swap_ra(p_stack_a);
	}
	return (1);
}

int	move_p_stack_b_to_p_stack_a(t_linked_satck *p_stack_a,
	t_linked_satck *p_stack_b)
{
	int	idx;
	int	max;

	if (!p_stack_a || !p_stack_b)
		error_exit(0);
	idx = 0;
	while (p_stack_b->p_top_element != NULL)
	{
		max = (p_stack_b->current_element_cnt) - 1;
		if (max_is_top(p_stack_b))
			while (max != p_stack_b->p_top_element->index)
				push_swap_rb(p_stack_b);
		else
			while (max != p_stack_b->p_top_element->index)
				push_swap_rrb(p_stack_b);
		push_swap_pa(p_stack_a, p_stack_b);
	}
	return (TRUE);
}

int	max_is_top(t_linked_satck *p_stack_b)
{
	t_stacknode	*node;
	int			half;
	int			max;

	if (!p_stack_b)
		error_exit(0);
	node = p_stack_b->p_top_element;
	half = (p_stack_b->current_element_cnt) / 2;
	max = (p_stack_b->current_element_cnt) - 1;
	while (half--)
	{
		if (max == node->index)
			return (TRUE);
		node = node->p_link;
	}
	return (FALSE);
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
	}
	return (rt_int_data);
}
			// node.index = stack_a->current_element_cnt;
			// push_linked_stack(stack_a, node);
			// p_stack_a_indexing(stack_a);