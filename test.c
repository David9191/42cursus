#include "./includes/ft_printf.h"

int	main(void)
{
	int a = ft_printf(" %d ", INT_MIN);
	int b = printf(" %d ", INT_MIN);
	printf("%d %d\n", a, b);
	// printf("%lu %lu\n", sizeof(int), sizeof(long));
}
