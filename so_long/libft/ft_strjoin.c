/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:30:37 by jislim            #+#    #+#             */
/*   Updated: 2021/12/11 17:41:03 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	total_len;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * total_len);
	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (*s1 != '\0' && i < len)
		str[i++] = *(s1++);
	while (*s2 != '\0' && i < total_len)
		str[i++] = *(s2++);
	str[i] = '\0';
	return (str);
}
