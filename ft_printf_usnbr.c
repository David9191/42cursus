/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_usnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:14:13 by jislim            #+#    #+#             */
/*   Updated: 2022/03/31 19:16:09 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_usnbr(unsigned int us_nbr)
{
	int	len;

	len = 0;
	if (us_nbr >= 10)
		len = len_usnbr(us_nbr / 10);
	return (++len);
}

int	print_usnbr(unsigned int us_nbr)
{
	int	len;

	ft_putusnbr_fd(us_nbr, 1);
	len = len_usnbr(us_nbr);
	return (len);
}
