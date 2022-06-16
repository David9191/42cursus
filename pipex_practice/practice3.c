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

	
}