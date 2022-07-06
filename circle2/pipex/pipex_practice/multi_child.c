#include "pipe.h"
#include <time.h>

void	printError(char *str)
{
	perror(str);
	exit(1);
}

int	main(int argc, char **argv)
{
	int		pipe_fd[2];
	int		j = 1, dummy, pid;
	char	str[1000];

	setbuf(stdout, NULL);
	printf("%lu Parent Started\n", clock());

	if (pipe(pipe_fd) == -1)
		printError("pipe");

	while (j < argc)
	{
		pid = fork();
		if (pid == -1)
			printError("fork");
		else if (pid == 0)
		{
			if (close(pipe_fd[0]) == -1)
				printError("close");
			/* 자식은 작업을 수행하고 완료되면 끝났음을 부모에게 알린다. */
			write(pipe_fd[1], argv[j], strlen(argv[j]));
			write(pipe_fd[1], "\n", 1);
			// printf("I'm printf %s\n", argv[j]);
			// printf("%s\n", argv[j]);
			if (close(pipe_fd[1]) == -1)
				printError("close");
			exit(0);
		}
		j++;
	}
	waitpid(pid, NULL, 0);
	// 이걸 안썼을 때는 n개 인자면 n - 1개만 읽었는데 waitpid로 자식들 다 끝날때까지 기다려주니 다 출력된다!
	if (close(pipe_fd[1]) == -1)
		printError("close");
	read(pipe_fd[0], str, 200);
	write(1, str, strlen(str));
	return (0);
}

/*
	int pdf[2];

	pipe(pdf);

	close(STDOUT_FILENO);
	dup(pdf[1]);
	=====================
	dup2(pdf[1], STDOUT_FILENO);
	// 디스크립터 1을 닫고 파이프의 쓰기 끝으로 재설정한다.
	close(pid[1]); // 호출 후에 사용하지 않는 디스크립터는 닫아준다.
*/