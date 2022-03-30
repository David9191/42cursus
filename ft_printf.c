/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:32:19 by jislim            #+#    #+#             */
/*   Updated: 2022/03/30 14:39:51 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			idx;
	va_list		ap;

	va_start(ap, format);
	idx = 0;
	while (format[idx] != '\0')
	{
		if (format[idx] == '%' && format[idx + 1] == 's')
			ft_putstr_fd(va_arg(ap, char *), 1);
		else if (format[idx] == '%' && format[idx + 1] == 'p')
		{
			ft_putstr_fd("0x", 1);
			hexa_print(va_arg(ap, unsigned long), 'p');
		}
		else if (format[idx] == '%' && format[idx + 1] == 'c')
			ft_putchar_fd(va_arg(ap, int), 1);
		else if (format[idx] == '%' && (format[idx + 1] == 'x'
				|| format[idx + 1] == 'X'))
			hexa_print(va_arg(ap, unsigned int), format[idx + 1]);
		else if (format[idx] == '%' && format[idx + 1] == '%')
			ft_putchar_fd('%', 1);
		else if (format[idx] == '%' && (format[idx + 1] == 'd'
				|| format[idx + 1] == 'i'))
			ft_putnbr_fd(va_arg(ap, int), 1);
		else if (format[idx] == '%' && format[idx + 1] == 'u')
			ft_putusnbr_fd(va_arg(ap, unsigned int), 1);
		else
		{
			ft_putchar_fd(format[idx++], 1);
			continue ;
		}
		idx += 2;
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	int	a = 2147483647;
	ft_printf("%%%cft_print\n-----------\n%s\t%p\n%d	%i\n%s\n%x\n%X\n%u\n\n",
	'-', "hello world!", "hello world!", a, a, "개행 굿", 56789, 56789, -1);
	printf("%%%cprint\n-----------\n%s\t%p\n%d	%i\n%s\n%x\n%X\n%u",
	'-', "hello world!", "hello world!", a, a, "개행 굿", 56789, 56789, -1);
	// ft_printf("%d", 2147483648); 이 경우 어떻게 할거임? 고려하지마?
	return (0);
}
