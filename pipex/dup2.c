#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("tmp.bbb", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Create tmp.bbb");
		exit(1);
	}

	dup2(fd, 1);
	// dup2() 함수를 사용해 기존 파일 기술자(fd)를 1번 파일 기술자로 복사한다.
	// 이제 1번 파일 기술자로 출력하면 더 이상 표준 출력이 아닌 fr가 가리키는 파일로 출력된다.
	printf("DUP2: Standard Output Redirection\n");

	close(fd);
}
