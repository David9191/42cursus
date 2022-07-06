/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:08:04 by jislim            #+#    #+#             */
/*   Updated: 2022/04/05 14:11:58 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_nbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
		len = len_nbr(nbr / 10);
	return (++len);
}

int	print_nbr(int nbr)
{
	int	len;

	ft_putnbr_fd(nbr, 1);
	if (nbr == -2147483648)
		return (11);
	else if (nbr < 0)
	{
		nbr *= -1;
		len = len_nbr(nbr) + 1;
	}
	else
		len = len_nbr(nbr);
	return (len);
}
