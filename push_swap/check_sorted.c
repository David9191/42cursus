/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:22:21 by jislim            #+#    #+#             */
/*   Updated: 2022/05/28 01:42:51 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sort(t_linked_satck *stack)
{
	t_stacknode	*node;
	t_stacknode	*next;

	node = stack->p_top_element;
	while (node->p_link)
	{
		next = node->p_link;
		if (node->data > next->data)
			return ;
		node = next;
	}
	error_exit(0);
}
