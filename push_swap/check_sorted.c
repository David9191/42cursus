/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:22:21 by jislim            #+#    #+#             */
/*   Updated: 2022/05/27 21:30:59 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sort(t_linked_satck *stack)
{
	t_stacknode	*node;
	t_stacknode	*next;

	node = stack->p_top_element;
	while (node)
	{
		next = node->p_link;
		if (!node || !next)
			return ;
		if (node->data > next->data)
			error_exit(0);
		node = next;
	}
}
