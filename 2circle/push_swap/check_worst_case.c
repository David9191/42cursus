/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_worst_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:05:02 by jislim            #+#    #+#             */
/*   Updated: 2022/06/02 20:38:26 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_worst(int *arr, int size)
{
	int	idx;

	idx = 0;
	while (idx < size - 1)
	{
		if (arr[idx] < arr[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}

int	check_where_min(t_stack	*stack_a)
{
	t_stacknode	*node;
	int			arr[15];
	int			j;
	int			arr_idx;

	node = stack_a->p_top_element;
	arr_idx = 0;
	ft_memset(arr, 0, sizeof(int) * 15);
	while (arr_idx < 15)
	{
		j = 0;
		while (node->p_link && j < (stack_a->current_element_cnt) / 15)
		{
			arr[arr_idx] += node->index;
			node = node->p_link;
			j++;
		}
		arr_idx++;
	}
	if (check_worst(arr, 15))
		return (WORST);
	else
		return (NOT_WORST);
}
