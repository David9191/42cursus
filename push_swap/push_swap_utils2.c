/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:19:11 by jislim            #+#    #+#             */
/*   Updated: 2022/05/27 17:22:35 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parsing(char **argv)
{
	int	*arr;
	int	idx;

	idx = 1;
	while (argv[idx])
	{

	}
	arr[idx] = ft_atoi(argv[idx + 1]);
	idx++;
	return (arr);
}

// int	*parsing(int argc, char **argv)
// {
// 	int	idx;
// 	int	*arr;
// 	idx = 0;
// 		while (idx < argc)
// 		{
// 			// 왜 idx + 1? argv[0]은 a.out(실행파일이 담겨있음.)
// 			arr[idx] = ft_atoi(argv[idx + 1]);
// 			idx++;
// 		}
// 	return (arr);
	// int	*data;
	// if (strchr(argv[i], ' ')
	// 	str_input(argv[i], &data);
	// 	str_input
	// 		char	**str;
	// 		str = split(parameter_str, ' ');
	// 		if (!str) return (FALSE); || exit();
	// 		while
	// 			check_input(str[i], &data);
	// else
	// 	check_input(argv[i], &data);
	// 	check_input
	// 		check int range
	// 		long long	num;
	// 		int			*i;
	// 		int			len;
	// 		len = ft_strlen(s);
	// 		len -= (s[0] == '-' || s[0] == '+');
	// 		num = ft_atoll(s);
	// 		if (!(ft_isnum(s) && len == ft_numlen(num)))
	// 			error_exit();
	// 		if (num > 2147483647 || num < -2147483648)
	// 			error_exit();
	// 		if (check_dup(*a, num))
	// 			error_exit();
	// 		i = (int *) malloc(sizeof(int));
	// 		if (!i)
	// 			exit(EXIT_FAILURE);
	// 		*i = num;
	// 		ft_lstadd_back(a, ft_lstnew(i));
	// return (TRUE);
// }

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
		if (node->data < next->data)
		{
			node->index--;
			next->index++;
		}
		next = next->p_link;
	}
	return (TRUE);
}

t_linked_satck	*create_p_stack_a(int *arr, int argc)
{
	t_linked_satck	*p_stack_a;
	t_stacknode		node;

	if (!arr)
		return (NULL);
	p_stack_a = create_linked_stack();
	while (argc--)
	{
		node.data = *arr;
		node.index = p_stack_a->current_element_cnt;
		push_linked_stack(p_stack_a, node);
		if (node.index > 0)
			p_stack_a_indexing(p_stack_a);
		arr++;
	}
	return (p_stack_a);
}

int	move_p_stack_a_to_p_stack_b(t_linked_satck *p_stack_a,
	t_linked_satck *p_stack_b, int chunk)
{
	int			num;
	int			index;
	t_stacknode	node;

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
		return (FALSE);
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
		return (FALSE);
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
