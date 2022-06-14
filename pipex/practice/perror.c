#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int	main()
{
	// access는 시스템 호출 함수니까 오류시 -1을 리턴해서 이렇게 조건문을 작성해줌.
	if (access("test.txt", R_OK) == -1)
	{
		perror("test.txt");
		// perror("이거 뭐야");
		// perror(NULL);
		exit(1);
	}
}
