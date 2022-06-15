#include "pipe.h"

// ls -al | grep "filename" -> stdout
// parent wait
int	main(void)
{
	int		pipe_fd[2];
	pid_t	pid;
	char	buf[10000];
	char	*argv[] = {"ls", "-al"};
	int		status;

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		dup2(pipe_fd[1], 1);
		execve("/bin/ls", argv, NULL);
	}
	else
	{
		waitpid(pid, NULL, 0);
		read(pipe_fd[0], buf, 1000);
		write(1, buf, strlen(buf));
	}
}