#include <stdio.h>
#include <unistd.h>

// cspdiuxX%

int	ft_printf(const char *format, ...)
{
	int	idx;
	int	*p_idx = &idx;

	printf("%s\n", format);
	printf("%%\n");
	printf("%n", p_idx); // prints nothing / just curious
	printf("%4$s %3$d %1$d %2$d", 10, 20, 30, "fourth subsequent argument");
	// optional filed. notation n$ means n번째 후속인자를 선택할거다.

	// printf("hello \0 world\0"); error
	return (0);
}

int	main(void)
{
	char a = 'A';
	int b = 10;
	int c = 12;
	unsigned int d = 0;
	write(1, &d, 1);

	printf("%c\n", a + b);
	printf("%d\n", a + b);
	printf("%d\n", c);
	printf("%i\n", -1);
	printf("%u\n", 0);
	printf("%u\n", -2);
	printf("%u\n", 2147483647);
	ft_printf("Hello world!");
	return (0);
}
