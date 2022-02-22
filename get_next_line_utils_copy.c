/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_copy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:45 by jislim            #+#    #+#             */
/*   Updated: 2022/02/23 02:51:30 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int to_find)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
	{
		if (str[len] == to_find)
			return ((char *)&str[len]); // 이 부분 애매. 다시 공부해보기.
		len++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	idx;

	idx = 0;
	if (!str)
		return (0);
	while (str[idx] != '\0')
		idx++;
	return (idx);
}

char	*ft_strjoin(char *dest, char *src)
{
	char	*ret_str;
	size_t	dst_idx;
	size_t	src_idx;
	// printf("dest's address : %p\n", dest);
	if (!dest) // 처음에 backup만들어 주기.
	{
		dest = (char *)malloc(sizeof(char) * 1);
		// if (!dest)
		// 	return (NULL);
		*dest = '\0';
	}
	if (!dest || !src)
		return (NULL);
	ret_str = malloc(sizeof(char) * ((ft_strlen(dest) + ft_strlen(src)) + 1));
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

// 여기부터 다시보기
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
	if (!str)
	{
		free(str);
		return (NULL);
	}
	while (str[len] != '\n' && str[len])
		len++;
	ret_str = malloc(sizeof(char) * (ft_strlen(str) - len));
	if (!ret_str)
		return (NULL);
	ret_str_idx = 0;
	len++; // \n 한 칸 뒤로 이동시켜줌.
	while (str[len])
		ret_str[ret_str_idx++] = str[len++];
	ret_str[ret_str_idx] = '\0';
	free(str);
	return (ret_str);
}
