#include "get_next_line.h"

int	main(void)
{
	char buff[50];
	int fd = open("hello.txt", O_RDONLY);
	read(fd, buff, 10);
	printf("%s\n", buff);
}
