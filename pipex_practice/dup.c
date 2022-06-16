#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int fd, fd2;

	fd = open("tmp.aaa", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Create tmp.aaa");
		exit(1);
	}
	close(1);

	fd2 = dup(fd);
	// dup(fd)를 실행하면 파일 기술자 fd가 가리키는 파일에 새로운 파일 기술자가 지정된다.
	// 15행에서 1번을 닫았기 때문에 현재 가장 작은 값은 1이고, 이 값이 새로운 파일 기술자로 할당된다.
	if (fd == fd2)
		printf("same\n");
	else
		printf("fd != fd2 : different\n");
	printf("FD=%d\n", fd);
	printf("DUP FD=%d\n", fd2);
	printf("Standard Output Redirection\n");

	close(fd);
}