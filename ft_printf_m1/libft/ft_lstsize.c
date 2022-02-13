/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:18:01 by jislim            #+#    #+#             */
/*   Updated: 2021/12/08 15:25:17 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lst_size;

	if (lst == NULL)
		return (0);
	lst_size = 1;
	while (lst -> next != NULL)
	{
		lst_size++;
		lst = lst -> next;
	}
	return (lst_size);
}
