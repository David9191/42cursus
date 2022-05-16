#include "push_swap.h"

int	*parsing(int argc, char **argv)
{
	// int	idx;


	// idx = 0;
	// while (idx < argc)
	// {
	// 	// 왜 idx + 1? argv[0]은 a.out(실행파일이 담겨있음.)
	// 	arr[idx] = ft_atoi(argv[idx + 1]);
	// 	idx++;
	// }
	// return (arr);
	
	// int	*data;
	// if (strchr(argv[i], ' ')
	// 	str_input(argv[i], &data);
	// 	str_input
	// 		char	**str;
	// 		str = split(parameter_str, ' ');
	// 		if (!str) return (FALSE); || exit();
	// 		while
	// 			check_input(str[i], &data);
	// else
	// 	check_input(argv[i], &data);
	// 	check_input
	// 		check int range
	// 		long long	num;
	// 		int			*i;
	// 		int			len;

	// 		len = ft_strlen(s);
	// 		len -= (s[0] == '-' || s[0] == '+');
	// 		num = ft_atoll(s);
	// 		if (!(ft_isnum(s) && len == ft_numlen(num)))
	// 			error_exit();
	// 		if (num > 2147483647 || num < -2147483648)
	// 			error_exit();
	// 		if (check_dup(*a, num))
	// 			error_exit();
	// 		i = (int *) malloc(sizeof(int));
	// 		if (!i)
	// 			exit(EXIT_FAILURE);
	// 		*i = num;
	// 		ft_lstadd_back(a, ft_lstnew(i));
	return (TRUE);
}
int	pStackA_indexing(LinkedStack *pStackA)
{
	StackNode	*node;
	StackNode	*next;

	if (!pStackA)
		return (FALSE);
	node = pStackA->pTopElement;
	// next = node->pLink;로 하면 맨 마지막의 pLink는 NULL이니까 안들어감.
	next = node;
	while (next)
	{
		if (node->data < next->data)
		{
			node->index--;
			next->index++;
		}
		next = next->pLink;
	}
	return (TRUE);
}
LinkedStack	*create_pStackA(int *arr, int argc)
{
	// 정렬 후, 인덱싱 처리를 해주자.
	// ⬆안 됨. 왜? 정렬할려면 스택을 엄청 많이 바꿔야됨.
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
		node.index = pStackA->currentElementCount;
		pushLS(pStackA, node);
		// 여기다가 인덱싱 처리 함수 추가?
		if (node.index > 0)
			pStackA_indexing(pStackA);
		arr++;
	}
	return (pStackA);
}
int	move_pStackA_to_pStackB(LinkedStack *pStackA, LinkedStack *pStackB, int chunk)
{
	int			num;
	int			index;
	StackNode	node;

	num = 0;
	// ft_printf("초기 cnt : %d\n", pStackA->currentElementCount);
	while (pStackA->currentElementCount)
	{
		index = pStackA->pTopElement->index;
		// index++;
		node.index = index;
		if (index <= num)
		{
			// ft_printf("cnt : %d, ", pStackA->currentElementCount);
			// ft_printf("index : %d, num : %d, pb\n", index, num);
			push_swap_pb(pStackA, pStackB);
			num++;
		}
		else if (num < index && index <= num + chunk)
		{
			// ft_printf("cnt : %d, ", pStackA->currentElementCount);
			// ft_printf("index : %d, num : %d, pb, ra\n", index, num);
			push_swap_pb(pStackA, pStackB);
			push_swap_rb(pStackB);
			num++;
		}
		else if (index > num + chunk)
		{
			// ft_printf("cnt : %d, ", pStackA->currentElementCount);
			// ft_printf("BBBBB cnt : %d, ", pStackB->currentElementCount);
			// ft_printf("index : %d, num : %d, ra\n", index, num);
			push_swap_ra(pStackA);
		}
		// else if 2번째로 2번 들어감
	}
	return (1);
}
int	move_pStackB_to_pStackA(LinkedStack *pStackA, LinkedStack *pStackB)
{
	int	idx;
	int	max;

	if (!pStackA || !pStackB)
		return (FALSE);
	idx = 0;
	// pStackB->pTopElement->index얘랑 따로 변수로 만들어서 하는 거랑 시간비교 해보기.
	while (pStackB->pTopElement != NULL)
	{
		max = (pStackB->currentElementCount) - 1;
		if (max_is_top(pStackB))
			while (max != pStackB->pTopElement->index)
				push_swap_rb(pStackB);
		else
			while (max != pStackB->pTopElement->index)
				push_swap_rrb(pStackB);
		push_swap_pa(pStackA, pStackB);
	}
	return(TRUE);
}
int	max_is_top(LinkedStack *pStackB)
{
	StackNode	*node;
	int			half;
	int			max;

	if (!pStackB)
		return (FALSE);
	node = pStackB->pTopElement;
	half = (pStackB->currentElementCount) / 2;
	max = (pStackB->currentElementCount) - 1;
	while (half--)
	{
		if (max == node->index)
			return (TRUE);
		node = node->pLink;
	}
	return (FALSE);
}