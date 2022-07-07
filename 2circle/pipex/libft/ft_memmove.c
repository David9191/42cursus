/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 03:26:48 by jislim            #+#    #+#             */
/*   Updated: 2021/11/17 03:26:48 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		p_dst = (unsigned char *)dst;
		p_src = (unsigned char *)src;
		while (len--)
			*p_dst++ = *p_src++;
	}
	else
	{
		p_dst = (unsigned char *)dst + (len - 1);
		p_src = (unsigned char *)src + (len - 1);
		while (len--)
			*p_dst-- = *p_src--;
	}
	return (dst);
}
