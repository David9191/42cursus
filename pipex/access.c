#include <sys/errno.h>
#include <stdio.h>
#include <unistd.h>

extern int  errno;

int main(void)
{
	int perm;

	if (access("linux.bak", F_OK) == -1 && errno == ENOENT)
		printf("linux.bak : File not exitst.\n");

	perm = access("linux.txt", R_OK);

	if (perm == 0)
		printf("linux.txt : Read permmission is permmitted.\n");
	else if (perm == -1 && errno == ENOENT)
		printf("linux.txt : Read permmission is not permmitted.\n");
}