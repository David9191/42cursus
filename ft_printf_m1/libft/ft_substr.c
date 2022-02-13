/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:43:03 by jislim            #+#    #+#             */
/*   Updated: 2021/12/05 00:45:52 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ps;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (len == 0 || ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ps = (char *)s + start;
	i = 0;
	while (i < len && ps[i] != '\0')
	{
		str[i] = ps[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
