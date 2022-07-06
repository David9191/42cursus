/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:26:21 by jislim            #+#    #+#             */
/*   Updated: 2021/11/12 01:26:21 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t	idx;
	size_t	k;

	if (!s1 || !s2)
		return (NULL);
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	idx = 0;
	while (s1[idx] && idx < size)
	{
		k = 0;
		while (s2[k] == s1[idx + k] && (idx + k) < size)
		{
			k++;
			if (s2[k] == '\0')
				return ((char *)&s1[idx]);
		}
		idx++;
	}
	return (NULL);
}
