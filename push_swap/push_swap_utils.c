#include "push_swap.h"

int push_swap_sa(LinkedStack *pStackA)
{
	StackNode	*temp;

	if (!pStackA || !(pStackA->pTopElement))
		return (0);
	temp = pStackA->pTopElement;
	pStackA->pTopElement = pStackA->pTopElement->pLink;
	temp->pLink = pStackA->pTopElement->pLink;
	pStackA->pTopElement->pLink = temp;
	return (1);
}
int push_swap_sb(LinkedStack *pStackB)
{
	StackNode	*temp;

	if (!pStackB || !(pStackB->pTopElement))
		return (0);
	temp = pStackB->pTopElement;
	pStackB->pTopElement = pStackB->pTopElement->pLink;
	temp->pLink = pStackB->pTopElement->pLink;
	pStackB->pTopElement->pLink = temp;
	return (1);
}
int push_swap_pa(LinkedStack *pStackA, LinkedStack *pStackB)
{
	StackNode	node;
	int			check;

	if (!pStackB || !(pStackB->currentElementCount))
		return (0);
	node.data = popLS(pStackB);
	check = pushLS(pStackA, node);
	if (!check)
		return (0);
	return (1);
}
int push_swap_pb(LinkedStack *pStackA, LinkedStack *pStackB)
{
	StackNode	node;
	int			check;

	if (!pStackA || !(pStackA->currentElementCount))
		return (0);
	node.data = popLS(pStackA);
	check = pushLS(pStackB, node);
	if (!check)
		return (0);
	return (1);
}
int push_swap_ra(LinkedStack *pStackA)
{
	StackNode	*top;
	StackNode	*bottom;

	if (!pStackA || 2 > pStackA->currentElementCount)
		return (0);
	top = pStackA->pTopElement;
	// top을 1인덱스로 바꾸는 작업
	pStackA->pTopElement = pStackA->pTopElement->pLink;
	bottom = pStackA->pTopElement;
	while (bottom->pLink)
		bottom = pStackA->pTopElement->pLink;
	bottom->pLink = top;
	top->pLink = NULL;
}
int push_swap_rb(LinkedStack *pStackB)
{
	StackNode	*top;
	StackNode	*bottom;

	if (!pStackB || 2 > pStackB->currentElementCount)
		return (0);
	top = pStackB->pTopElement;
	// top을 1인덱스로 바꾸는 작업
	pStackB->pTopElement = pStackB->pTopElement->pLink;
	bottom = pStackB->pTopElement;
	while (bottom->pLink)
		bottom = pStackB->pTopElement->pLink;
	bottom->pLink = top;
	top->pLink = NULL;
}
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
		bottom = pStackA->pTopElement->pLink;
	}
	pre_bottom->pLink = NULL;
	pStackA->pTopElement = bottom;
	bottom->pLink = top;
}
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
}