/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:06:54 by jislim            #+#    #+#             */
/*   Updated: 2022/05/28 13:56:26 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_int_data
{
	int	*arr;
	int	cnt;
}		t_int_data;


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

void			parsing(char **argv, t_int_data *data);
int				ft_atoi_push(const char *str);
int				check_value(const char *str, long long result, long long sign);
void			split_free_all(char **str);
void			check_dup(t_linked_satck *stack);
void			check_sort(t_linked_satck *stack);
int				p_stack_a_indexing(t_linked_satck *p_stack_a);
t_linked_satck	*create_p_stack_a(int *arr, int argc);
int				move_p_stack_a_to_p_stack_b(t_linked_satck *p_stack_a,
					t_linked_satck *p_stack_b, int chunk);
int				move_p_stack_b_to_p_stack_a(t_linked_satck *p_stack_a,
					t_linked_satck *p_stack_b);
int				max_is_top(t_linked_satck *p_stack_b);
void			error_exit(int error);

t_int_data		*create_int_data(int max_cnt);
void			put_on_stack_a(t_linked_satck *stack, t_int_data *data);

#endif
