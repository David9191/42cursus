/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:13:46 by jislim            #+#    #+#             */
/*   Updated: 2021/11/11 22:13:46 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s2;

	s2 = (char *)s;
	while (*s2 != '\0')
		s2++;
	while ((*s2 != (char)c) && s2 > s)
		s2--;
	if (*s2 == (char)c)
		return ((char *)s2);
	else
		return (NULL);
}
