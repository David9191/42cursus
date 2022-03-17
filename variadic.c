#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *, ...);

void	printfNum(int args, ...)
{
	va_list ap;
	int		num;

	va_start(ap, args);
	for (int i = 0; i < args; i++)
	{
		num = va_arg(ap, int);
		printf("%d ", num);
	}
	va_end(ap);
	printf("\n");
}

int main(void)
{
	printfNum(1, 10);
	printfNum(2, 10, 20);
	printfNum(3, 10, 20, 30);
	printfNum(4, 10, 20, 30, 40);

	return (0);
}
