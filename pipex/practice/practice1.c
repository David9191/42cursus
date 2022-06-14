#include "pipe.h"
// 1. fork + child execve(ls -al)

int	main(void)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
		printf("I'm Child\n");

	if (pid > 0)
	{
		printf("I'm Parent\n");
		waitpid(pid, &status, 0);
		printf("status : %d\n", status);
	}
	return (0);
}