/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:45 by jislim            #+#    #+#             */
/*   Updated: 2021/12/25 03:40:59 by jislim           ###   ########.fr       */
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
	size_t	idx;

	idx = 0;
	if (!s)
		return (0);
	while (s[idx] != '\0')
		idx++;
	return (idx);
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
	dest = NULL;
	return (ret_str);
}

char	*get_line_endl(char *str)
{
	char	*ret_str;
	size_t	endl_idx;
	size_t	ret_str_idx;
	size_t	str_idx;

	endl_idx = 0;
	while (str[endl_idx] != '\n' && str[endl_idx] != '\0')
		endl_idx++;
	ret_str = malloc(sizeof(char) * (endl_idx + 2));
	if (!ret_str)
		return (NULL);
	ret_str_idx = 0;
	str_idx = 0;
	while (ret_str_idx <= endl_idx)
		ret_str[ret_str_idx++] = str[str_idx++];
	ret_str[ret_str_idx] = '\0';
	return (ret_str);
}

char	*save_backup(char *str)
{
	char	*ret_str;
	size_t	len;
	size_t	ret_str_idx;

	// 12\nㅠㅠ
	// sdfjklasdf
	// sj
	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	// printf("len : %ld\n", len);
	ret_str = malloc(sizeof(char) * (ft_strlen(str) - len));
	if (!ret_str)
		return (NULL);
	ret_str_idx = 0;
	len++;
	while (len < ft_strlen(str))
		ret_str[ret_str_idx++] = str[len++];
	ret_str[ret_str_idx] = '\0';
	free(str);
	return (ret_str);
}
