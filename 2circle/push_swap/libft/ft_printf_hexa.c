/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:08:12 by jislim            #+#    #+#             */
/*   Updated: 2022/05/01 00:36:47 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	decimal_to_hexa_upper(unsigned int hex)
{
	int		len;
	char	ch;

	len = 0;
	ch = hex % 16;
	if (hex >= 16)
		len = decimal_to_hexa_upper(hex / 16);
	if (ch >= 0 && ch < 10)
		ch += '0';
	else if (ch >= 10 && ch < 16)
		ch = ch - 10 + 'A';
	write(1, &ch, 1);
	return (++len);
}

int	decimal_to_hexa_lower(unsigned int hex)
{
	int		len;
	char	ch;

	len = 0;
	ch = hex % 16;
	if (hex >= 16)
		len = decimal_to_hexa_lower(hex / 16);
	if (ch >= 0 && ch < 10)
		ch += '0';
	else if (ch >= 10 && ch < 16)
		ch = ch - 10 + 'a';
	write(1, &ch, 1);
	return (++len);
}

int	print_hexa(unsigned int hexa, char conv)
{
	int	rt_len;

	if (conv == 'X')
		rt_len = decimal_to_hexa_upper(hexa);
	if (conv == 'x')
		rt_len = decimal_to_hexa_lower(hexa);
	return (rt_len);
}
