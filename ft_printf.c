#include <stdio.h>
#include <unistd.h>

// cspdiuxX%

// int	ft_printf(const char *format, ...)
// {
// 	va_list	ap;

// 	return (0);
// }

int	main(void)
{
	// char a = 'A';
	// int b = 10;
	// int c = 12;

	// printf("%c\n", a + b);
	// printf("%d\n", 2147483648);
	// printf("%i\n", 2147483648);
	// printf("%d\n", c);
	// printf("%i\n", -1);
	// printf("%u\n", 0);
	// printf("%u\n", -2147483647);
	unsigned int a = 2147483647;
	unsigned int *b = &a;
	write(1, b, 8);
	// printf("%u\n", 2147483647);
	// printf("%lu %lu\n", sizeof(int), sizeof(va_list[1]));
	// ft_printf("Hello world!");
	return (0);
}
