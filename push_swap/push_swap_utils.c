#include "push_swap.h"

// sa (swap a) : Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
int push_swap_sa(LinkedStack *pStackA)
{
	StackNode	*temp;

	if (!pStackA || 2 > pStackA->currentElementCount)
		return (0);
	temp = pStackA->pTopElement;
	pStackA->pTopElement = pStackA->pTopElement->pLink;
	temp->pLink = pStackA->pTopElement->pLink;
	pStackA->pTopElement->pLink = temp;
	return (1);
}
// sb (swap b) : Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
int push_swap_sb(LinkedStack *pStackB)
{
	StackNode	*temp;

	if (!pStackB || 2 > pStackB->currentElementCount)
		return (0);
	temp = pStackB->pTopElement;
	pStackB->pTopElement = pStackB->pTopElement->pLink;
	temp->pLink = pStackB->pTopElement->pLink;
	pStackB->pTopElement->pLink = temp;
	return (1);
}
// pa (push a) : Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
int push_swap_pa(LinkedStack *pStackA, LinkedStack *pStackB)
{
	StackNode	*node;
	int			check;

	if (!pStackB || 1 > pStackB->currentElementCount)
		return (0);
	node = popLS(pStackB);
	if (!node)
		return (0);
	check = pushLS(pStackA, *node);
	// 여기서 free를 안해주면 메인에서 deleteStack해도 이미 node는 pStack에 포함되어 있지 않기 때문에
	// free를 못해줌.
	free (node);
	if (!check)
		return (0);
	return (1);
}
// pb (push b) : Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
int push_swap_pb(LinkedStack *pStackA, LinkedStack *pStackB)
{
	StackNode	*node;
	int			check;

	if (!pStackA || 1 > pStackA->currentElementCount)
		return (0);
	node = popLS(pStackA);
	if (!node)
		return (0);
	check = pushLS(pStackB, *node);
	free (node); // popLS에서 free하면 이미 메모리 반환 후 이므로 쓰레기 값이 들어감.
	// free 했을 시 -> Process 12544: 0 leaks for 0 total leaked bytes.
	// free 안했을 시 -> Process 12416: 100 leaks for 1600 total leaked bytes.
	// 클러스터 맥에서 a push_swap.c push_swap_util* ./libft/*.c -g3 -fsanitize=address 해보기
	if (!check)
		return (0);
	return (1);
}
// ra (rotate a) : Shift up all elements of stack a by 1.
// The first element becomes the last one.
int push_swap_ra(LinkedStack *pStackA)
{
	StackNode	*top;
	StackNode	*bottom;

	if (!pStackA || 2 > pStackA->currentElementCount)
		return (0);
	top = pStackA->pTopElement;
	// top을 1인덱스로 바꾸는 작업
	pStackA->pTopElement = pStackA->pTopElement->pLink;
	bottom = top;
	while (bottom->pLink)
		bottom = bottom->pLink;
	bottom->pLink = top;
	top->pLink = NULL;
	return (1);
}
// rb (rotate b) : Shift up all elements of stack b by 1.
// The first element becomes the last one.
int push_swap_rb(LinkedStack *pStackB)
{
	StackNode	*top;
	StackNode	*bottom;

	if (!pStackB || 2 > pStackB->currentElementCount)
		return (0);
	top = pStackB->pTopElement;
	// top을 1인덱스로 바꾸는 작업
	pStackB->pTopElement = pStackB->pTopElement->pLink;
	bottom = top;
	while (bottom->pLink)
		bottom = bottom->pLink;
	bottom->pLink = top;
	top->pLink = NULL;
	return (1);
}
// rra (reverse rotate a) : Shift down all elements of stack a by 1.
// The last element becomes the first one.
int push_swap_rra(LinkedStack *pStackA)
{
	StackNode	*top;
	StackNode	*pre_bottom;
	StackNode	*bottom;

	if (!pStackA || 2 > pStackA->currentElementCount)
		return (0);
	top = pStackA->pTopElement;
	bottom = top;
	while (bottom->pLink)
	{
		pre_bottom = bottom;
		bottom = bottom->pLink;
	}
	pre_bottom->pLink = NULL;
	pStackA->pTopElement = bottom;
	bottom->pLink = top;
	return (1);
}
// rrb (reverse rotate b) : Shift down all elements of stack b by 1.
// The last element becomes the first one.
int push_swap_rrb(LinkedStack *pStackB)
{
	StackNode	*top;
	StackNode	*pre_bottom;
	StackNode	*bottom;

	if (!pStackB || 2 > pStackB->currentElementCount)
		return (0);
	top = pStackB->pTopElement;
	bottom = top;
	while (bottom->pLink)
	{
		pre_bottom = bottom;
		bottom = bottom->pLink;
	}
	pre_bottom->pLink = NULL;
	pStackB->pTopElement = bottom;
	bottom->pLink = top;
	return (1);
}
