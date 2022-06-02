/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:06:54 by jislim            #+#    #+#             */
/*   Updated: 2022/06/02 19:41:57 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_int_data
{
	int	*arr;
	int	cnt;
}		t_int_data;

int				push_swap_sa(t_stack *stack_a);
int				push_swap_sb(t_stack *stack_b);
int				push_swap_pa(t_stack *stack_a, t_stack *stack_b);
int				push_swap_pb(t_stack *stack_a, t_stack *stack_b);
int				push_swap_ra(t_stack *stack_a);
int				push_swap_rb(t_stack *stack_b);
int				push_swap_rra(t_stack *stack_a);
int				push_swap_rrb(t_stack *stack_b);

void			parsing(char **argv, t_int_data *data);
void			is_possible(char **str);
int				ft_atoi_push(const char *str);
int				check_value(const char *str, long long result, long long sign);
void			split_free_all(char **str);
void			check_dup(t_stack *stack);
void			check_sort(t_stack *stack);
int				stack_a_indexing(t_stack *stack_a);
int				move_stack_a_to_stack_b(t_stack *stack_a,
					t_stack *stack_b, int chunk, int check_min);
int				move_stack_b_to_stack_a(t_stack *stack_a, t_stack *stack_b);
int				max_is_top(t_stack *stack_b);
void			error_exit(int error);

t_int_data		*create_int_data(int max_cnt);
void			put_on_stack_a(t_stack *stack, t_int_data *data);
int				get_chunk(t_int_data *data);
int				less_than_or_equal_five(t_stack *stack_a, t_stack *stack_b);
int				in_case_three(t_stack *stack_a, int first, int second,
					int third);
int				in_case_five(t_stack *stack_a, t_stack *stack_b);
int				min_to_stack_b(t_stack *stack_a, t_stack *stack_b);
int				find_min(t_stack *stack_a);
void			check_and_sort(t_stack *stack_a, t_stack *stack_b,
					t_int_data *data);
int				check_descending(t_stack *stack);

void			sort_number(t_stack *stack_a, t_stack *stack_b,
					t_int_data *data);
void			move_stack_a_to_stack_b_descen(t_stack *stack_a,
					t_stack *stack_b, t_int_data *data);
void			check_and_sort(t_stack *stack_a, t_stack *stack_b,
					t_int_data *data);
int				check_where_min(t_stack	*stack_a);

# define IN_TOP		1
# define IN_BOTTOM	0

#endif
