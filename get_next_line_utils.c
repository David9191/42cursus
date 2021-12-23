/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:45 by jislim            #+#    #+#             */
/*   Updated: 2021/12/24 01:40:41 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	if (c < 0)
		return (0);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *dest, char *src)
{
	char	*ret_str;
	size_t	dst_idx;
	size_t	src_idx;

	ret_str = malloc(sizeof(char) * ft_strlen(dest) + ft_strlen(src) + 1);
	if (!ret_str)
		return (NULL);
	dst_idx = 0;
	while (dest[dst_idx] != '\0')
	{
		ret_str[dst_idx] = dest[dst_idx];
		dst_idx++;
	}
	src_idx = 0;
	while (src[src_idx] != '\0')
	{
		ret_str[dst_idx + src_idx] = src[src_idx];
		src_idx++;
	}
	ret_str[dst_idx + src_idx] = '\0';
	free(dest);
	return (ret_str);
}

char	*get_line_endl(char *str)
{
	char	*ret_str;
	size_t	endl_idx;
	size_t	ret_str_idx;
	size_t	str_idx;

	endl_idx = 1;
	while (str[endl_idx] != '\n')
		endl_idx++;
	ret_str = malloc(sizeof(char) * (endl_idx + 1));
	if (!ret_str)
		return (NULL);
	ret_str_idx = 0;
	str_idx = 0;
	while (str[str_idx] != '\0')
		ret_str[ret_str_idx++] = str[str_idx++];
	ret_str[ret_str_idx] = '\0';
	return (ret_str);
}

size_t	loc_nl(char *str)
{
	size_t	len;

	len = 1;
	while (str[len] != '\n')
		len++;
	return (len);
}
