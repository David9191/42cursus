/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jisung9105@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:45 by jislim            #+#    #+#             */
/*   Updated: 2022/03/04 16:04:51 by jislim           ###   ########.fr       */
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

	if (!backup)
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
	size_t	str_idx;
	size_t	ret_str_idx;

	str_idx = 0;
	while (str[str_idx] && str[str_idx] != '\n')
		str_idx++;
	if (!str[str_idx])
	{
		free(str);
		return (NULL);
	}
	ret_str = malloc(sizeof(char) * (ft_strlen(str) - str_idx));
	if (!ret_str)
		return (NULL);
	ret_str_idx = 0;
	str_idx++;
	while (str[str_idx])
		ret_str[ret_str_idx++] = str[str_idx++];
	ret_str[ret_str_idx] = '\0';
	free(str);
	return (ret_str);
}
