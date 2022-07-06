/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:53:34 by jislim            #+#    #+#             */
/*   Updated: 2021/11/09 14:53:34 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int					sign;
	unsigned long long	result;
	unsigned long long	long_min;

	sign = 1;
	result = 0;
	long_min = LONG_MIN * -1ULL;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		result = (result * 10) + (*(nptr++) - '0');
	if (result > LONG_MAX && sign == 1)
		return (-1);
	else if (result > long_min && sign == -1)
		return (0);
	return ((int)result * sign);
}
