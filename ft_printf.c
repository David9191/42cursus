#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// cspdiuxX%

// int	ft_printf(const char *format, ...)
// {
// 	va_list	ap;

// 	return (0);
// }
	// printf("%p\t%p\t%lu\n", &a, b, sizeof(b));
	// printf("%x\t%X\n", 10, 150);

int	main(void)
{
	unsigned int a = 2147483647;
	unsigned int *b = &a;
	unsigned long long	ad = (unsigned long long)b;
	char *hexa = (char *)malloc(sizeof(char) * 13);
	int	hexa_idx = 11;

	while (hexa_idx >= 0)
	{
		char hexa_c = ad % 16;
		if (hexa_c >= 0 && hexa_c < 10)
			hexa[hexa_idx] = hexa_c + '0';
		else if (hexa_c >= 10 && hexa_c < 16)
			hexa[hexa_idx] = hexa_c - 10 + 'a';
		hexa_idx -= 1;
		if (ad >= 16)
			ad /= 16;
	}
	hexa[12] = '\0';
	write(1, "0x", 2);
	while (*hexa)
	{
		write(1, hexa, 1);
		hexa++;
	}
	printf("\n%p", b);
	return (0);
}
