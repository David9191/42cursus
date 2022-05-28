/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:18:42 by jislim            #+#    #+#             */
/*   Updated: 2022/05/28 14:16:05 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_value(const char *str, long long result, long long sign)
{
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		result = (result * 10) + (*str - '0');
		str++;
		if ((sign == 1 && (result > 2147483647))
			|| (sign == -1 && (result > 2147483648)))
			error_exit(1);
	}
	if (*str)
		error_exit(1);
	return ((int)(result * sign));
}

int	ft_atoi_push(const char *str)
{
	long long	result;
	long long	sign;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	str += (*str == '-' || *str == '+');
	result = check_value(str, result, sign);
	return (result);
}
