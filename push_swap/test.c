#include "push_swap.h"

int	main()
{
	int	arr[] = { 100, 500, 300, 400, 200 };
	char *s = "-12345";
	int len = 0;
	unsigned long long a = LONG_MAX;
	// 1. 스택에 추가한다.
	// 2. 그 후 스택에 맨 위에 애를 맨 끝까지 돌면서 자기보다 크면 인덱스++
	printf("%ld\n%ld\n%llu\n", LONG_MAX, LONG_MIN, a + 1);

	for (int i = 0; i < 6; i++)
		if (s[i])
			len++;
	printf("%d\n", len);
	len -= (s[0] == '-' || s[0] == '+');
	printf("%d\n", len);
}
