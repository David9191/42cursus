/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:32:19 by jislim            #+#    #+#             */
/*   Updated: 2022/03/31 19:55:00 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	breidge_format(va_list ap, char conv)
{
	int	check;

	check = 0;
	if (conv == '%' || conv == 'c')
		check += print_char(va_arg(ap, int));
	else if (conv == 's')
		check += print_str(va_arg(ap, char *));
	else if (conv == 'd' || conv == 'i')
		check += print_nbr(va_arg(ap, int));
	else if (conv == 'u')
		check += print_usnbr(va_arg(ap, unsigned int));
	else if (conv == 'x' || conv == 'X')
		check += print_hexa(va_arg(ap, unsigned int));
	else if (conv == 'p')
		check += print_hexa_ptr(va_arg(ap, unsigned long));
	return (check);
}

int	ft_printf_hub(va_list ap, const char *format, int cnt_print)
{
	int	check;
	int	idx;

	idx = 0;
	while (format[idx] != '\0')
	{
		if (format[idx] == '%')
		{
			check = breidge_format(ap, format[++idx]);
			if (check == 0)
				return (0);
			cnt_print += check;
		}
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

	if (!format || !(*format))
		return (0);
	va_start(ap, format);
	cnt_print = ft_printf_hub(ap, format, 0);
	va_end(ap);
	return (cnt_print);
}

int	main(void)
{
	int	a = 2147483647;
	// ft_printf("%c\n%c\n", '%', '-');
	ft_printf("%% %c\n %s\t %p\n %d %i\n %x\n %X\n %u\n\n",
	'-', "hello world!", &a, a, a, 56789, 56789, -1);
	// printf("%%%cprint\n-----------\n%s\t%p\n%d	%i\n%s\n%x\n%X\n%u",
	// '-', "hello world!", "hello world!", a, a, "개행 굿", 56789, 56789, -1);
	// ft_printf("%d", 2147483648); 이 경우 어떻게 할거임? 고려하지마? 다른 분은 이 경우 뭐 나오는지 물어봐야겠다.
	// -2147483648이 나왔다. 나도 그냥 하면 될 거 같다. 고려 안해도 됨. 위의 일자로부터 2일 후.
	return (0);
}
