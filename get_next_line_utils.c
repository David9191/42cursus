/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:45 by jislim            #+#    #+#             */
/*   Updated: 2021/12/26 00:57:37 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	if (c == '\0')
		return (1);
	while (*s != '\0')
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
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

	if (!dest)
	{
		dest = (char *)malloc(1 * sizeof(char));
		dest[0] = '\0';
	}
	if (!dest || !src)
		return (NULL);
	ret_str = malloc(sizeof(char) * ft_strlen(dest) + ft_strlen(src) + 1);
	if (!ret_str)
		return (NULL);
	dst_idx = -1;
	while (dest[++dst_idx] != '\0')
		ret_str[dst_idx] = dest[dst_idx];
	src_idx = -1;
	while (src[++src_idx] != '\0')
		ret_str[dst_idx++] = src[src_idx];
	ret_str[dst_idx] = '\0';
	free(dest);
	return (ret_str);
}

char	*get_line_endl(char *str)
{
	char	*ret_str;
	size_t	endl_idx;
	size_t	idx;

	endl_idx = 0;
	while (str[endl_idx] != '\n' && str[endl_idx])
		endl_idx++;
	ret_str = malloc(sizeof(char) * (endl_idx + 2));
	if (!ret_str)
		return (NULL);
	idx = -1;
	while (++idx <= endl_idx)
		ret_str[idx] = str[idx];
	ret_str[idx] = '\0';
	return (ret_str);
}

char	*save_backup(char *str)
{
	char	*ret_str;
	size_t	len;
	size_t	ret_str_idx;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (!str[len])
	{
		free(str);
		return (NULL);
	}
	ret_str = malloc(sizeof(char) * (ft_strlen(str) - len));
	if (!ret_str)
		return (NULL);
	ret_str_idx = 0;
	len++;
	while (str[len])
		ret_str[ret_str_idx++] = str[len++];
	ret_str[ret_str_idx] = '\0';
	free(str);
	return (ret_str);
}
