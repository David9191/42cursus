#include "./src/ft_printf.h"

int	main(void)
{
	int a = 5, b = 3;
	// int a = ft_printf(" %d ", INT_MIN);
	// int b = printf(" %d ", INT_MIN);
	// printf(NULL);
	// ft_printf(NULL);
	// printf("%lu %lu\n", sizeof(int), sizeof(long));
	ft_printf("%d, %d\n", a, b);
}
