/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 03:28:08 by jislim            #+#    #+#             */
/*   Updated: 2021/11/17 03:28:08 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret_p;

	ret_p = malloc(size * count);
	if (!(ret_p))
		return (NULL);
	ft_bzero(ret_p, size * count);
	return (ret_p);
}
