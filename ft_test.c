#include "ft_printf.h"

int	print_char(int ch)
{
	ft_putchar_fd(ch, 1);
	return (1);
}


int	main(void)
{
	int len = print_char('-');
	printf("\n%d\n", len);
	return (0);
}
