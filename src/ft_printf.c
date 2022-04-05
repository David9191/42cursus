/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:32:19 by jislim            #+#    #+#             */
/*   Updated: 2022/04/05 14:11:22 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	breidge_format(va_list ap, char conv)
{
	int	check;

	check = 0;
	if (conv == '%')
		check += print_char('%');
	else if (conv == 'c')
		check += print_char(va_arg(ap, int));
	else if (conv == 's')
		check += print_str(va_arg(ap, char *));
	else if (conv == 'd' || conv == 'i')
		check += print_nbr(va_arg(ap, int));
	else if (conv == 'u')
		check += print_usnbr(va_arg(ap, unsigned int));
	else if (conv == 'x' || conv == 'X')
		check += print_hexa(va_arg(ap, unsigned int), conv);
	else if (conv == 'p')
		check += print_hexa_ptr(va_arg(ap, unsigned long));
	return (check);
}

int	ft_printf_hub(va_list ap, const char *format, int cnt_print)
{
	int	idx;

	idx = 0;
	while (format[idx] != '\0')
	{
		if (format[idx] == '%')
			cnt_print += breidge_format(ap, format[++idx]);
		else
			cnt_print += print_char(format[idx]);
		idx++;
	}
	return (cnt_print);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt_print;

	va_start(ap, format);
	cnt_print = ft_printf_hub(ap, format, 0);
	va_end(ap);
	return (cnt_print);
}
