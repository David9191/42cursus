/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:56:51 by jislim            #+#    #+#             */
/*   Updated: 2022/05/27 21:11:15 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(t_linked_satck *stack)
{
	t_stacknode	*node;
	t_stacknode	*next;

	node = stack->p_top_element;
	while (node)
	{
		next = node->p_link;
		while (next)
		{
			if (node->data == next->data)
				error_exit(1);
			next = next->p_link;
		}
		node = node->p_link;
	}
}
