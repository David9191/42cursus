/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:37:16 by jislim            #+#    #+#             */
/*   Updated: 2021/11/11 22:37:16 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dst_idx;
	size_t	src_idx;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (size + src_len);
	dst_idx = 0;
	while (dest[dst_idx] != '\0')
		dst_idx++;
	src_idx = 0;
	while (src[src_idx] != '\0' && (dst_idx + 1) < size)
		dest[dst_idx++] = src[src_idx++];
	dest[dst_idx] = '\0';
	return (dst_len + src_len);
}
