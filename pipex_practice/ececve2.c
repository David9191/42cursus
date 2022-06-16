#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	char	*argv[2] = { "ls", "-a" };

	switch (pid = fork())
	{
	case -1 :
		perror("fork");
		break ;
	case 0 :
		printf("--> Child Process\n");
		if (execve("ls", argv, envp))

		break ;
	
	default:
		break ;
	}
}