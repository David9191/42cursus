/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:12:03 by jislim            #+#    #+#             */
/*   Updated: 2021/12/08 17:17:47 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret_lst;
	t_list	*curr;

	if (!lst || !f)
		return (NULL);
	ret_lst = ft_lstnew(f(lst -> content));
	if (!ret_lst)
		return (NULL);
	curr = ret_lst;
	lst = lst -> next;
	while (lst)
	{
		curr -> next = ft_lstnew(f(lst -> content));
		if (!curr -> next)
		{
			ft_lstclear(&ret_lst, del);
			return (0);
		}
		curr = curr -> next;
		lst = lst -> next;
	}
	return (ret_lst);
}
