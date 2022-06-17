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
			// execlp("ls", "ls", NULL);
			write(1, "COME HERE ITER==1\n", strlen("COME HERE ITER==1\n"));
			if (execve("/bin/", argv2, envp) == -1)
				write(1, "HOLY SHIT ITER==1\n", strlen("HOLY SHIT ITER==1\n"));
			print_error("execve");
		}
		else if (pid == 0 && iter == 0)
		{
			close(pipe_fd[1]);
			dup2(pipe_fd[0], 0);
			close(pipe_fd[0]);
			// 이렇게 되면 원래는 stdin에서 읽어오는데 위에서 dup2를 해줘서 파이프에서 읽어온다.
			char	*argv3[] = {"wc", "-l", NULL};
			// execlp("wc", "wc", "-l", NULL);
			write(1, "COME HERE ITER==0\n", strlen("COME HERE ITER==0\n"));
			if (execve("/usr/bin/", argv3, envp) == -1)
				write(1, "HOLY SHIT ITER==0\n", strlen("HOLY SHIT ITER==0\n"));

			print_error("execve");
		}
	}
	write(1, "COME HERE PARENT\n", strlen("COME HERE PARENT\n"));
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	wait(NULL);
	wait(NULL);
	// read(pipe_fd[0], buf, 300);
	// write(1, buf, strlen(buf));
	exit(EXIT_SUCCESS);
}