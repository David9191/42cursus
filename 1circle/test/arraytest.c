#include <stdio.h>

void	check(int *arr)
{
	int	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
}

int	main(void)
{
	int arr[2] = { 0, 1 };

	printf("BEFORE CHECK\n");
	for (int idx = 0; idx < 2; idx++)
	{
		printf("arr[%d] : %d\n", idx, arr[idx]);
	}
	check(arr);
	printf("AFTER CHECK\n");
	for (int idx = 0; idx < 2; idx++)
	{
		printf("arr[%d] : %d\n", idx, arr[idx]);
	}
}