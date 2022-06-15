#include "pipe.h"
// 2. pipe 부모한테 받은 값을 출력(부모 -> 자식)

int	main(void)
{
	int		pipe_fd[2];
	pid_t	pid;
	char	*argv[] = {};
	char	buf[10000];
	
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(1);
	}

	// printf("pipe_fd[0] : %d pipe_fd[1] : %d\n", pipe_fd[0], pipe_fd[1]);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		close(pipe_fd[1]);
		read(pipe_fd[0], buf, strlen("Hi Child~ I'm your Parent\n"));
		write(1, &buf, strlen(buf)); // 1
		close(pipe_fd[0]);
		write(1, "I'm Child. It's done.\n", strlen("I'm Child. It's done.\n")); // 2
	}
	else
	{
		close(pipe_fd[0]);
		write(pipe_fd[1], "Hi Child~ I'm your Parent\n", strlen("Hi Child~ I'm your Parent\n"));
		close(pipe_fd[1]);
		waitpid(pid, NULL, 0);
		write(1, "Ok, I'm Parent. It's all done\n", strlen("Ok, I'm Parent. It's all done\n")); // 3
	}

	return (0);
}