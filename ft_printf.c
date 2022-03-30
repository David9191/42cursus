/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:32:19 by jislim            #+#    #+#             */
/*   Updated: 2022/03/30 15:23:20 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	breidge_format(va_list ap, char conversion, int cnt_print)
{
	if (conversion == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (conversion == 'p')
	{
		ft_putstr_fd("0x", 1);
		hexa_print(va_arg(ap, unsigned long), 'p');
	}
	else if (conversion == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if ((conversion == 'x'
			|| conversion == 'X'))
		hexa_print(va_arg(ap, unsigned int), conversion);
	else if (conversion == '%')
		ft_putchar_fd('%', 1);
	else if ((conversion == 'd'
			|| conversion == 'i'))
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (conversion == 'u')
		ft_putusnbr_fd(va_arg(ap, unsigned int), 1);
	else
		return (0);
	return (cnt_print);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		check;
	int		cnt_print;
	int		idx;

	if (!format)
		return (0);
	va_start(ap, format);
	cnt_print = 0;
	idx = 0;
	while (format[idx] != '\0')
	{
		if (format[idx] == '%')
		{
			check = breidge_format(ap, format[++idx], cnt_print);
			if (check == 0)
				return (0);
			cnt_print += check;
		}
		else
		{
			ft_putchar_fd(format[idx], 1);
			cnt_print++;
		}
		idx++;
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
	// ft_printf("%d", 2147483648); 이 경우 어떻게 할거임? 고려하지마? 다른 분은 이 경우 뭐 나오는지 물어봐야겠다.
	return (0);
}
