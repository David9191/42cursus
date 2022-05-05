#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int					sign;
	unsigned long long	result;
	unsigned long long	long_min;

	sign = 1;
	result = 0;
	long_min = LONG_MIN * -1ULL;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		result = (result * 10) + (*(nptr++) - '0');
	if (result > LONG_MAX && sign == 1)
		return (-1);
	else if (result > long_min && sign == -1)
		return (0);
	return ((int)result * sign);
}
t_arr	*parsing(char *str)
{
	t_arr	s_arr;
	int		*arr;
	int		size;
	int		result;

	s_arr = malloc(sizeof(t_arr));
	while (*str)
	{
		result = ft_atoi(str);
	}
	// arr = malloc(sizeof(int) * argc);
	return (s_arr);
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