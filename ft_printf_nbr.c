/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:08:04 by jislim            #+#    #+#             */
/*   Updated: 2022/03/31 18:59:50 by jislim           ###   ########.fr       */
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
	len = len_nbr(nbr);
	return (len);
}
