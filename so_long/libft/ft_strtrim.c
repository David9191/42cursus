/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:54:18 by jislim            #+#    #+#             */
/*   Updated: 2022/06/24 14:03:40 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_set(char *set, char s1_c)
{
	size_t	idx;

	idx = 0;
	while (set[idx] != '\0')
	{
		if (set[idx] == s1_c)
			return (1);
		idx++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	begin;
	size_t	end;
	size_t	idx;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (!ft_strlen(s1))
		return (ft_strdup(""));
	begin = 0;
	while (s1[begin] && find_set((char *)set, s1[begin]))
		begin++;
	end = ft_strlen(s1) - 1;
	while (end > begin && find_set((char *)set, s1[end]))
		end--;
	str = (char *)malloc(sizeof(char) * (end - begin + 2));
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (begin <= end)
		str[idx++] = s1[begin++];
	str[idx] = '\0';
	return (str);
}
