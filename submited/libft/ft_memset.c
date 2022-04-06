/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 03:27:16 by jislim            #+#    #+#             */
/*   Updated: 2021/11/17 03:27:16 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p_b;
	unsigned char	cpy_c;
	size_t			i;

	p_b = (unsigned char *)b;
	cpy_c = (unsigned char)c;
	i = 0;
	while (i < len)
		p_b[i++] = cpy_c;
	return (b);
}
