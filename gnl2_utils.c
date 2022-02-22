/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:52:23 by jislim            #+#    #+#             */
/*   Updated: 2022/02/22 23:58:50 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl2.h"

size_t	ft_strlen(const char *str)
{
	size_t	idx;

	idx = 0;
	if (!str)
		return (NULL);
	while (str[idx])
		idx++;
	return (idx);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
