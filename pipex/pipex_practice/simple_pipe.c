#include "pipe.h"

# define BUF_SIZE	10

void	printError(char *str)
{
	perror(str);
	exit(1);
}

int	main(int argc, char **argv)
{
	int		pipe_fd[2];
	char	buf[BUF_SIZE];
	ssize_t	numRead = 1;

	if (argc != 2 || strcmp(argv[1], "--help") == 0)
		perror("argv[0]");
	if (pipe(pipe_fd) == -1)
		printError("pipe");

	switch (fork())
	{
	case -1 :
		printError("fork");
		break;
	case 0 :
		if (close(pipe_fd[1]) == -1)
			printError("close");
		while (1)
		{
			numRead = read(pipe_fd[0], buf, BUF_SIZE);
			if (numRead == -1)
				printError("read");
			if (numRead == 0)
				break ;
			if (write(STDOUT_FILENO, buf, numRead) != numRead)
				printError("write");
		}
		if (write(STDOUT_FILENO, "\n", 1) != 1)
			printError("write");
		if (close(pipe_fd[0]) == -1)
				printError("close");
		break;
	default :
		if (close(pipe_fd[0]) == -1)
			printError("close");
		if (write(pipe_fd[1], argv[1], strlen(argv[1])) != strlen(argv[1]))
			printError("write");
		if (close(pipe_fd[1]) == -1)
			printError("close");
		wait(NULL);
		exit(EXIT_SUCCESS);
		break;
	}
}