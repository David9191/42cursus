#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *, ...);

void	printfNum(int args, ...)
{
	va_list ap; // 가변인자 포인터
	int		num;

	va_start(ap, args); // 포인터 시작지점 지정
	for (int i = 0; i < args; i++)
	{
		num = va_arg(ap, int); // int의 크기만큼 순방향 이동
		printf("%d ", num); // args 다음 거 출력
	}
	va_end(ap); // ap = NULL;
	printf("\n");
}

int main(void)
{
	// printfNum(1, 10);
	// printfNum(2, 10, 20);
	// printfNum(3, 10, 20, 30);
	printfNum(4, 10, 20, 30, 40); // 이 경우에는 args = 4, 출력은 10, 20, 30, 40이 출력됨.

	return (0);
}
