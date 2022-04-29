#include "push_swap.h"

int	*parsing(int argc, char **argv)
{
	int	*arr;
	int	idx;

	arr = malloc(sizeof(int) * argc);
	idx = 0;
	while (idx < argc)
	{
		// 왜 idx + 1? argv[0]은 a.out(실행파일이 담겨있음.)
		arr[idx] = ft_atoi(argv[idx + 1]);
		idx++;
	}
	return (arr);
}
LinkedStack	*pStackA_indexing(int *arr)
{
	LinkedStack	*pStackA;
	StackNode	node;

	if (!arr)
		return (NULL);
	pStackA = createLinkedStack();
	while (*arr)
	{
		node.data = *arr;
		pushLS(pStackA, node);
		arr++;
	}
	return (pStackA);
}
int	move_pStackA_to_pStackB(LinkedStack *pStackA, LinkedStack *pStackB, int chunk)
{
	int	num;
	int	data;

	if (!pStackA || !pStackB)
		return (0);
	num = 0;
	data = 1;
	while (pStackA->pTopElement || data)
	{
		data = pStackA->pTopElement->data;
		int c = pStackA->currentElementCount;
		if (!c) return (0);
		if (data <= num)
		{
			push_swap_pb(pStackA, pStackB);
			num++;
		}
		else if (num < data && data <= num + chunk)
		{
			push_swap_pb(pStackA, pStackB);
			push_swap_rb(pStackB);
			num++;
		}
		else if (num + chunk < data)
			push_swap_ra(pStackA);
	}
	return (1);
}
// int	move_pStackB_to_pStackA(LinkedStack *pStackA, LinkedStack *pStackB)
// {
// 	int	half;
// 	int	idx;

// 	if (!pStackA || !pStackB)
// 		return (NULL);
// 	half = (pStackB->currentElementCount) / 2;
// 	idx = 0;
// 	while (pStackB->currentElementCount)
// 	{

// 	}
// 	push_swap_pa(pStackA, pStackB);
// }
