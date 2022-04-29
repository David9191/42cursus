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
	StackNode	node;
	int			check;

	if (!pStackB || 1 > pStackB->currentElementCount)
		return (0);
	node.data = popLS(pStackB);
	check = pushLS(pStackA, node);
	if (!check)
		return (0);
	return (1);
}
// pb (push b) : Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
int push_swap_pb(LinkedStack *pStackA, LinkedStack *pStackB)
{
	StackNode	node;
	int			check;

	if (!pStackA || 1 > pStackB->currentElementCount)
		return (0);
	node.data = popLS(pStackA);
	check = pushLS(pStackB, node);
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
