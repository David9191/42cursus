/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jisung9105@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:52:23 by jislim            #+#    #+#             */
/*   Updated: 2022/03/04 21:46:14 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl2.h"

size_t	ft_strchr(char *backup, int to_find)
{
	size_t	idx;
	
	if (!backup)
		return (NULL);
	idx = 0;
	while (backup[idx])
	{
		if (backup[idx] == to_find)
			return (idx + 1);
		idx++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*strjoin(char *backup, char *buf)
{
	char	*ret_str;
	int		ret_str_idx;
	int		buf_idx;

	if (!backup)
	{
		backup = malloc(sizeof(char) * 1);
		if (!backup)
			return (NULL);
		*backup = '\0';
	}
	ret_str = malloc(sizeof(char) * (ft_strlen(backup) + ft_strlen(buf) + 1));
	if (!ret_str)
		return (NULL);
	ret_str_idx = -1;
	while (backup[++ret_str_idx])
		ret_str[ret_str_idx] = backup[ret_str_idx];
	buf_idx = 0;
	while (buf[buf_idx])
		ret_str[ret_str_idx++] = buf[buf_idx++];
	ret_str[ret_str_idx] = '\0'; // here
	free(backup);
	return (ret_str);
}

