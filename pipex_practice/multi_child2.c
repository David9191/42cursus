#include "pipe.h"

void	print_error(char *str)
{
	perror(str);
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	char	buf[300];
	int		pid, iter = 2;

	if (pipe(pipe_fd) == -1)
		print_error("pipe");

	while (iter--)
	{
		if ((pid = fork()) == -1)
			print_error("fork");
		else if (pid == 0 && iter == 1)
		{
			close(pipe_fd[0]);
			dup2(pipe_fd[1], 1);
			close(pipe_fd[1]);
			char	*argv2[] = {"ls", NULL};
			execlp("ls", "ls", NULL);
			// execve("/bin/", argv2, envp);
			print_error("execve");
		}
		else if (pid == 0 && iter != 1)
		{
			close(pipe_fd[1]);
			dup2(pipe_fd[0], 0);
			close(pipe_fd[0]);
			// 이렇게 되면 원래는 stdin에서 읽어오는데 위에서 dup2를 해줘서 파이프에서 읽어온다.
			char	*argv3[] = {"wc", "-l", NULL};
			execlp("wc", "wc", "-l", NULL);
			// execve("/usr/bin/", argv3, envp);
			print_error("execve");
		}
	}
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	wait(NULL);
	wait(NULL);
	// read(pipe_fd[0], buf, 300);
	// write(1, buf, strlen(buf));
	exit(EXIT_SUCCESS);
}