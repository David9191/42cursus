/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_copy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jisung9105@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:45 by jislim            #+#    #+#             */
/*   Updated: 2022/02/28 21:25:28 by jislim           ###   ########.fr       */
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
		*dest = '\0';
	}
	if (!dest || !src) // instead 52-53 lines
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

// here 여기부터 다시보기
char	*get_line_endl(char *str)
{
	char	*ret_str;
	size_t	idx;

	idx = 0;
	if (!str[idx])
		return (NULL);
	while (str[idx] != '\n' && str[idx])
		idx++;
	ret_str = malloc(sizeof(char) * (idx + 2));
	if (!ret_str)
		return (NULL);
	idx = 0;
	while (str[idx] && str[idx] != '\n')
	{
		ret_str[idx] = str[idx];
		idx++;
	}
	if (str[idx] == '\n')
		ret_str[idx++] = '\n';
	ret_str[idx] = '\0';
	return (ret_str);
}

char	*save_backup(char *str)
{
	char	*ret_str;
	size_t	idx;
	size_t	ret_str_idx;

	// abcdef\nabc
	idx = 0;
	while (str[idx] && str[idx] != '\n')
		idx++;
	if (!str[idx]) // 만약 뉴라인이 없다면 그냥 내보내기(저장할 게  없으니까)
	{
		free(str);
		return (NULL);
	}
	ret_str = malloc(sizeof(char) * (ft_strlen(str) - idx));
	if (!ret_str)
		return (NULL);
	ret_str_idx = 0;
	idx++; // \n 한 칸 뒤로 이동시켜줌.
	while (str[idx])
		ret_str[ret_str_idx++] = str[idx++];
	ret_str[ret_str_idx] = '\0';
	free(str);
	return (ret_str);
}
