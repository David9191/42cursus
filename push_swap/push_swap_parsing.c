/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:39:00 by jislim            #+#    #+#             */
/*   Updated: 2022/06/03 00:08:02 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_free_all(char **str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		free (str[idx]);
		idx++;
	}
	free (str);
}

void	is_possible(char **str)
{
	int	i;
	int	j;

	i = 0;
	if (!str[0])
		error_exit(1);
	while (str[i])
	{
		j = 0;
		if (str[i][0] == '\0' || str[i] == NULL)
			error_exit(1);
		while (str[i][j])
		{
			if ((str[i][j] == '+' || str[i][j] == '-')
				&& str[i][j + 1] == '\0')
				error_exit(1);
			j++;
		}
		i++;
	}
}

void	parsing(char **argv, t_int_data *data)
{
	char		**str;
	int			i;
	int			j;
	int			k;

	if (argv && data)
	{
		i = 1;
		k = 0;
		while (argv[i])
		{
			str = ft_split(argv[i], ' ');
			j = 0;
			is_possible(str);
			while (str[j])
			{
				data->arr[k++] = ft_atoi_push(str[j++]);
				(data->cnt)++;
			}
			i++;
			split_free_all(str);
		}
	}
	else
		error_exit(0);
}

void	put_on_stack_a(t_stack *stack, t_int_data *data)
{
	t_stacknode	node;
	int			iter;

	if (stack && data)
	{
		iter = (data->cnt) - 1;
		while (iter >= 0)
		{
			node.data = data->arr[iter];
			node.index = iter;
			push_linked_stack(stack, node);
			stack_a_indexing(stack);
			iter--;
		}
		return ;
	}
	error_exit(0);
}

int	stack_a_indexing(t_stack *stack_a)
{
	t_stacknode	*node;
	t_stacknode	*next;

	if (stack_a)
	{
		node = stack_a->p_top_element;
		next = node;
		while (next)
		{
			if (node->data > next->data)
			{
				node->index++;
				next->index--;
			}
			next = next->p_link;
		}
		return (TRUE);
	}
	else
		error_exit(0);
	return (0);
}
