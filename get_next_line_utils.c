/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:45 by jislim            #+#    #+#             */
/*   Updated: 2021/12/21 03:20:19 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && (i + 1) < size)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

char	*ft_strdup(const char *s1)
{
	char	*ps1;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	ps1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ps1))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ps1[i] = s1[i];
		i++;
	}
	ps1[i] = '\0';
	return (ps1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strchr(const char *s, int c)
{
	if (c < 0)
		return (NULL);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return (1);
}
