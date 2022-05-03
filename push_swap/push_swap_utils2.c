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
LinkedStack	*pStackA_indexing(int *arr, int argc)
{
	// 정렬 후, 인덱싱 처리를 해주자.
	// ⬆️안 됨. 왜? 정렬할려면 스택을 엄청 많이 바꿔야됨.
	LinkedStack	*pStackA;
	StackNode	node;

	if (!arr)
		return (NULL);
	pStackA = createLinkedStack();
	// argc 받아온 이유는 도저히 인트포인터의 총 길이를 못구하겠어서.
	// *arr로 하면 데이터가 0이면 while이 안돈다..
	while (argc--)
	{
		node.data = *arr;
		node.index = 0;
		pushLS(pStackA, node);
		// 여기다가 인덱싱 처리 함수 추가?
		arr++;
	}
	return (pStackA);
}
int	move_pStackA_to_pStackB(LinkedStack *pStackA, LinkedStack *pStackB, int chunk)
{
	int			num;
	int			data;
	StackNode	node;

	num = 0;
	ft_printf("초기 cnt : %d\n", pStackA->currentElementCount);
	while (pStackA->currentElementCount)
	{
		data = pStackA->pTopElement->data;
		// data++;
		node.data = data;
		if (data <= num)
		{
			ft_printf("cnt : %d, ", pStackA->currentElementCount);
			ft_printf("data : %d, num : %d, pb\n", data, num);
			push_swap_pb(pStackA, pStackB);
			num++;
		}
		else if (num < data && data <= num + chunk)
		{
			ft_printf("cnt : %d, ", pStackA->currentElementCount);
			ft_printf("data : %d, num : %d, pb, ra\n", data, num);
			push_swap_pb(pStackA, pStackB);
			push_swap_rb(pStackB);
			num++;
		}
		else if (data > num + chunk)
		{
			ft_printf("cnt : %d, ", pStackA->currentElementCount);
			ft_printf("BBBBB cnt : %d, ", pStackB->currentElementCount);
			ft_printf("data : %d, num : %d, ra\n", data, num);
			push_swap_ra(pStackA);
		}
		// else if 2번째로 2번 들어감
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
