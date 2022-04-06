/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:36:11 by jislim            #+#    #+#             */
/*   Updated: 2021/12/07 14:35:57 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	i_len(long n)
{
	size_t	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*fill_str_itoa(char	*str, int n, int len, int sign)
{
	int	cpy_len;

	cpy_len = len;
	if (sign == 1)
	{
		while (n >= 0 && len > 0)
		{
			str[--len] = (n % 10) + '0';
			n /= 10;
		}
		str[cpy_len] = '\0';
	}
	else if (sign == -1)
	{
		while (n > 0 && len > 0)
		{
			str[len--] = (n % 10) + '0';
			n /= 10;
		}
		str[0] = '-';
		str[cpy_len + 1] = '\0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			sign;
	size_t		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	len = i_len(n);
	if (sign == 1)
		str = (char *)malloc(sizeof(char) * (len + 1));
	else
		str = (char *)malloc(sizeof(char) * len + 2);
	if (str == NULL)
		return (NULL);
	str = fill_str_itoa(str, n, len, sign);
	return (str);
}
