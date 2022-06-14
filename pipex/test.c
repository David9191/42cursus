#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main()
{
	char cmd[] = {"/bin/ls"};
	char *argv[] = {"ls", "-l", NULL};
	char *envp[] = {NULL};

	printf("excute execve fundtion");
	execve(cmd, argv, envp);
	return (0);
}