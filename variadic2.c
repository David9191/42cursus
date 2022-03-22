#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *, ...);

void	printfNum(const char *str, ...)
{
	va_list ap; // 가변인자 포인터
	int		i;
	int		j;

	i = 0;
	va_start(ap, str); // 포인터 시작지점 지정
	if (str[i++] == '%')
	{
		if (str[i] == 's')
		{
			char *str2 = va_arg(ap, char *);
			j = 0;
			while (str2[j])
				write(1, &str2[j++], 1);
		}
	}
	va_end(ap); // ap = NULL;
	printf("\n");
}

int main(void)
{
	// printfNum(1, 10);
	// printfNum(2, 10, 20);
	// printfNum(3, 10, 20, 30);
	printfNum("%s", "Hello world");
	// 이 경우에는 args = 4, 출력은 10, 20, 30, 40이 출력됨.

	return (0);
}
