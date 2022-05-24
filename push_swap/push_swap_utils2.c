/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:19:11 by jislim            #+#    #+#             */
/*   Updated: 2022/05/24 20:57:35 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parsing(int argc, char **argv)
{
	int	*arr;
	int	idx;

	arr = malloc(sizeof(int) * argc);
	idx = 0;
	while (idx < argc)
	{
		// 왜 idx + 1? argv[0]은 a.out(실행파일이 담겨있음.)
		arr[idx] = ft_atoi(argv[idx + 1]);
		idx++;
	}
	return (arr);
}

// int	*parsing(int argc, char **argv)
// {
// 	int	idx;
// 	int	*arr;

// 	idx = 0;
// 	while (idx < argc)
// 	{
// 		// 왜 idx + 1? argv[0]은 a.out(실행파일이 담겨있음.)
// 		arr[idx] = ft_atoi(argv[idx + 1]);
// 		idx++;
// 	}
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
	// next = node->p_link;로 하면 맨 마지막의 p_link는 NULL이니까 안들어감.
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
	// 정렬 후, 인덱싱 처리를 해주자.
	// ⬆안 됨. 왜? 정렬할려면 스택을 엄청 많이 바꿔야됨.
	t_linked_satck	*p_stack_a;
	t_stacknode		node;

	if (!arr)
		return (NULL);
	p_stack_a = create_linked_stack();
	// argc 받아온 이유는 도저히 인트포인터의 총 길이를 못구하겠어서.
	// *arr로 하면 데이터가 0이면 while이 안돈다..
	while (argc--)
	{
		node.data = *arr;
		node.index = p_stack_a->current_element_cnt;
		push_linked_stack(p_stack_a, node);
		// 여기다가 인덱싱 처리 함수 추가?
		if (node.index > 0)
			p_stack_a_indexing(p_stack_a);
		arr++;
	}
	return (p_stack_a);
}

int	move_p_stack_a_to_p_stack_b(t_linked_satck *p_stack_a, t_linked_satck *p_stack_b,
		int chunk)
{
	int			num;
	int			index;
	t_stacknode	node;

	num = 0;
	// ft_printf("초기 cnt : %d\n", p_stack_a->current_element_cnt);
	while (p_stack_a->current_element_cnt)
	{
		index = p_stack_a->p_top_element->index;
		// index++;
		node.index = index;
		if (index <= num)
		{
			// ft_printf("cnt : %d, ", p_stack_a->current_element_cnt);
			// ft_printf("index : %d, num : %d, pb\n", index, num);
			push_swap_pb(p_stack_a, p_stack_b);
			num++;
		}
		else if (num < index && index <= num + chunk)
		{
			// ft_printf("cnt : %d, ", p_stack_a->current_element_cnt);
			// ft_printf("index : %d, num : %d, pb, ra\n", index, num);
			push_swap_pb(p_stack_a, p_stack_b);
			push_swap_rb(p_stack_b);
			num++;
		}
		else if (index > num + chunk)
		{
			// ft_printf("cnt : %d, ", p_stack_a->current_element_cnt);
			// ft_printf("BBBBB cnt : %d, ", p_stack_b->current_element_cnt);
			// ft_printf("index : %d, num : %d, ra\n", index, num);
			push_swap_ra(p_stack_a);
		}
		// else if 2번째로 2번 들어감
	}
	return (1);
}

int	move_p_stack_b_to_p_stack_a(t_linked_satck *p_stack_a, t_linked_satck *p_stack_b)
{
	int	idx;
	int	max;

	if (!p_stack_a || !p_stack_b)
		return (FALSE);
	idx = 0;
	// p_stack_b->p_top_element->index얘랑 따로 변수로 만들어서 하는 거랑 시간비교 해보기.
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
