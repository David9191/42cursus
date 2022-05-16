/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:18:42 by jislim            #+#    #+#             */
/*   Updated: 2022/05/16 18:03:14 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *nptr)
{
	long long	result;
	long long	sign;

	sign = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	nptr += (*nptr == '-' || *nptr == '+');
	while (*nptr != '\0' && (*nptr >= '0' || *nptr <= '9'))
	{
		result = (result * 10) + (*(nptr++) - '0');
		if ((sign > 0 && result < 0) || (sign < 0 && result > 0))
			return (-1);
	}
	if ((result > LONG_MAX && sign == 1)
		|| result > LONG_MAX + 1 && sign == -1)
		return (-1);
	return (result * sign);
}
