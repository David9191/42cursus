#include <stdio.h>

// cspdiuxX%

int	ft_printf(const char *format, ...)
{
	printf("%s\n", format);
	return (1);
}

int	main(void)
{
	ft_printf("Hello world");
	return (0);
}