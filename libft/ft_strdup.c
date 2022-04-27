/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 03:26:34 by jislim            #+#    #+#             */
/*   Updated: 2021/11/17 03:26:34 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ps1;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	ps1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ps1))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ps1[i] = s1[i];
		i++;
	}
	ps1[i] = '\0';
	return (ps1);
}
