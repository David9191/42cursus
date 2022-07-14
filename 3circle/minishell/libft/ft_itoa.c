/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuhan <seuhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:55:57 by seuhan            #+#    #+#             */
/*   Updated: 2022/07/12 00:23:00 by seuhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	num_len(long int num)
{
	int	count;

	count = 0;
	if (num == 0)
		count++;
	if (num < 0)
	{
		count++;
		num = num * (-1);
	}
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	int			sign;
	long int	buff;

	buff = n;
	len = num_len(buff);
	str = ft_gc_calloc((len + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	sign = 0;
	if (buff < 0)
	{
		buff = buff * -1;
		sign = -1;
	}
	while ((--len) >= 0)
	{
		str[len] = (buff % 10) + 48;
		buff = buff / 10;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}
