/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:30:14 by jislim            #+#    #+#             */
/*   Updated: 2022/04/05 14:11:35 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	decimal_to_hexa(unsigned long hex)
{
	int		len;
	char	ch;

	len = 0;
	ch = hex % 16;
	if (hex >= 16)
		len = decimal_to_hexa(hex / 16);
	if (ch >= 0 && ch < 10)
		ch += '0';
	else if (ch >= 10 && ch < 16)
		ch = ch - 10 + 'a';
	write(1, &ch, 1);
	return (++len);
}

int	print_hexa_ptr(unsigned long hexa)
{
	int	len;

	len = 2;
	write(1, "0x", 2);
	len += decimal_to_hexa(hexa);
	return (len);
}
