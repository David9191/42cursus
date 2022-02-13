/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:54:18 by jislim            #+#    #+#             */
/*   Updated: 2021/12/12 17:06:02 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_set(char *set, char s1_c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1_c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	begin;
	size_t	end;
	size_t	i;

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
	i = 0;
	while (begin <= end)
		str[i++] = s1[begin++];
	str[i] = '\0';
	return (str);
}
