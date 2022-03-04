/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_copy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jisung9105@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:45 by jislim            #+#    #+#             */
/*   Updated: 2022/03/04 15:09:08 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strchr(char *str, int to_find)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
	{
		if (str[len] == to_find)
			return (len + 1);
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

char	*ft_strjoin(char *backup, char *buf)
{
	char	*ret_str;
	size_t	ret_idx;
	size_t	buf_idx;
	
	if (!backup) // 처음에 backup만들어 주기.
	{
		backup = (char *)malloc(sizeof(char) * 1);
		if (!backup)
			return (NULL);
		*backup = '\0';
	}
	ret_str = malloc(sizeof(char) * ((ft_strlen(backup) + ft_strlen(buf)) + 1));
	if (!ret_str)
		return (NULL);
	ret_idx = -1;
	while (backup[++ret_idx] != '\0')
		ret_str[ret_idx] = backup[ret_idx];
	buf_idx = -1;
	while (buf[++buf_idx] != '\0')
		ret_str[ret_idx++] = buf[buf_idx];
	ret_str[ret_idx] = '\0';
	free(backup);
	return (ret_str);
}

char	*get_line_endl(char *backup)
{
	char	*ret_str;
	size_t	idx;

	idx = 0;
	if (backup[idx] == '\0') // exception NULL // why '\0'? because 54line.
	// 54라인에서 '\0'을 넣어줬고 널이라면 ret_str에 아무것도 안 채워넣어졌을 것이므로
	// 처음 문자가 '\0'이면 NULL인 것으로 판단한다. WOW
		return (NULL);
	while (backup[idx] && backup[idx] != '\n')
		idx++;
	ret_str = malloc(sizeof(char) * (idx + 2));
	if (!ret_str)
		return (NULL);
	idx = 0;
	while (backup[idx] && backup[idx] != '\n')
	{
		ret_str[idx] = backup[idx];
		idx++;
	}
	if (backup[idx] == '\n')
		ret_str[idx++] = '\n';
	ret_str[idx] = '\0';
	return (ret_str);
}

char	*save_backup(char *backup)
{
	char	*ret_str;
	size_t	idx;
	size_t	ret_str_idx;

	// abcdef\nabc
	idx = 0;
	while (backup[idx] && backup[idx] != '\n')
		idx++;
	if (!backup[idx]) // 만약 뉴라인이 없다면 그냥 내보내기(저장할 게  없으니까)
	{
		free(backup);
		return (NULL);
	}
	ret_str = malloc(sizeof(char) * (ft_strlen(backup) - idx));
	if (!ret_str)
		return (NULL);
	idx++; // \n 한 칸 뒤로 이동시켜줌.
	ret_str_idx = 0;
	while (backup[idx])
		ret_str[ret_str_idx++] = backup[idx++];
	ret_str[ret_str_idx] = '\0';
	free(backup);
	return (ret_str);
}