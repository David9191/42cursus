#include "./src/ft_printf.h"

int	main(void)
{
	int a = 5, b = 3;
	// int a = ft_printf(" %d ", INT_MIN);
	// int b = printf(" %d ", INT_MIN);
	// printf(NULL);
	// ft_printf(NULL);
	// printf("%lu %lu\n", sizeof(int), sizeof(long));
	ft_printf("%d, %d\n", a, b); // m1에서 값을 2개 이상 들고오면 에러 생김
	// 구조적 변호 필요
}
