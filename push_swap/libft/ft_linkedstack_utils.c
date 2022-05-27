/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkedstack_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:44:48 by jislim            #+#    #+#             */
/*   Updated: 2022/05/27 20:31:09 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_linked_stack_empty(t_linked_satck *pStack)
{
	if (pStack
		&& pStack->current_element_cnt == 0)
		return (TRUE);
	else
		return (FALSE);
}
