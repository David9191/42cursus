/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:32:19 by jislim            #+#    #+#             */
/*   Updated: 2022/03/29 19:39:04 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_print(unsigned int n, char d)
{
	char	c;

	c = n % 16;
	if (n >= 16)
	{
		n /= 16;
		x_print(n, d);
	}
	if (c >= 0 && c < 10)
		c += '0';
	else if (d == 'x' && c >= 10 && c < 16)
		c = c - 10 + 'a';
	else if (d == 'X' && c >= 10 && c < 16)
		c = c - 10 + 'A';
	write(1, &c, 1);
}

int	ft_printf(const char *format, ...)
{
	char		*str;
	int			idx;
	va_list		ap;

	va_start(ap, format);
	idx = 0;
	while (format[idx] != '\0')
	{
		if (format[idx] == '%' && format[idx + 1] == 's')
			ft_putstr_fd(va_arg(ap, char *), 1);
		else if (format[idx] == '%' && format[idx + 1] == 'p')
			str = printf_hexa(va_arg(ap, void *));
		else if (format[idx] == '%' && format[idx + 1] == 'c')
			ft_putchar_fd(va_arg(ap, int), 1);
		else if (format[idx] == '%' && (format[idx + 1] == 'x' || format[idx + 1] == 'X'))
			x_print(va_arg(ap, unsigned int), format[idx + 1]);
		else if (format[idx] == '%' && format[idx + 1] == '%')
			write(1, "%%", 1);
		else
		{
			write(1, &format[idx++], 1);
			continue ;
		}
		idx += 2;
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	ft_printf("%%%cft_print\n--------------------\n%s %p\n%s\n%x\n%X\n\n", '-', "hello world!", (void *)-1, "개행 굿", 123456789, 123456789);
	printf("%%%cprint\n--------------------\n%s %p\n%s\n%x\n%X", '-', "hello world!", (void *)-1, "개행 굿", 123456789, 123456789);

	return (0);
}
