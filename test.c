#include <stdio.h>
#include <unistd.h>

void	x_print(unsigned int n, char d)
{
	char	c;

	c = n % 16;
	if (n >= 16)
	{
		n /= 16;
		x_print(n, d);
	}
	if (c >= 0 && c < 10)
		c += '0';
	else if (d == 'x' && c >= 10 && c < 16)
		c = c - 10 + 'a';
	else if (d == 'X' && c >= 10 && c < 16)
		c = c - 10 + 'A';
	write(1, &c, 1);
}

int	main(void)
{
	x_print(123456789, 'X');
}
