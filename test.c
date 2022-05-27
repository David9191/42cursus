#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	test_exit()
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	printf("argv[0] : %s\n", argv[0]);
	printf("argv[1] : %s\n", argv[1]);
	printf("Hello\n");
	printf("before exit function\n");
	test_exit();
	printf("after exit function");
}
