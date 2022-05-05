/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:06:54 by jislim            #+#    #+#             */
/*   Updated: 2022/05/05 01:22:06 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_arr
{
	int	*arr;
	int	size;
	int	chunk;
}		t_arr;

int			push_swap_sa(LinkedStack *pStackA);
int			push_swap_sb(LinkedStack *pStackB);
int			push_swap_pa(LinkedStack *pStackA, LinkedStack *pStackB);
int			push_swap_pb(LinkedStack *pStackA, LinkedStack *pStackB);
int			push_swap_ra(LinkedStack *pStackA);
int			push_swap_rb(LinkedStack *pStackB);
int			push_swap_rra(LinkedStack *pStackA);
int			push_swap_rrb(LinkedStack *pStackB);

t_arr		*parsing(char *str);
int			pStackA_indexing(LinkedStack *pStackA);
LinkedStack	*create_pStackA(int *arr, int argc);
int			move_pStackA_to_pStackB(LinkedStack *pStackA, LinkedStack *pStackB, int chunk);
int			move_pStackB_to_pStackA(LinkedStack *pStackA, LinkedStack *pStackB);
int			max_is_top(LinkedStack *pStackB);

#endif
