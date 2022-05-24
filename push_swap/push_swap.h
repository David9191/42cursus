/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:06:54 by jislim            #+#    #+#             */
/*   Updated: 2022/05/24 20:24:37 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

int				push_swap_sa(t_linked_satck *p_stack_a);
int				push_swap_sb(t_linked_satck *p_stack_b);
int				push_swap_pa(t_linked_satck *p_stack_a,
					t_linked_satck *p_stack_b);
int				push_swap_pb(t_linked_satck *p_stack_a,
					t_linked_satck *p_stack_b);
int				push_swap_ra(t_linked_satck *p_stack_a);
int				push_swap_rb(t_linked_satck *p_stack_b);
int				push_swap_rra(t_linked_satck *p_stack_a);
int				push_swap_rrb(t_linked_satck *p_stack_b);

int				*parsing(int argc, char **argv);
int				p_stack_a_indexing(t_linked_satck *p_stack_a);
t_linked_satck	*create_p_stack_a(int *arr, int argc);
int				move_p_stack_a_to_p_stack_b(t_linked_satck *p_stack_a,
					t_linked_satck *p_stack_b, int chunk);
int				move_p_stack_b_to_p_stack_a(t_linked_satck *p_stack_a,
					t_linked_satck *p_stack_b);
int				max_is_top(t_linked_satck *p_stack_b);

#endif
