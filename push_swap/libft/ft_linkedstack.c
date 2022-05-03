#include "libft.h"

LinkedStack *createLinkedStack()
{
	LinkedStack	*rt_satck;

	rt_satck = malloc(sizeof(LinkedStack));
	if (!rt_satck)
		return (NULL);
	rt_satck->currentElementCount = 0;
	rt_satck->pTopElement = NULL;
	return (rt_satck);
}

int	pushLS(LinkedStack *pStack, StackNode element)
{
	StackNode	*node;

	if (!pStack)
		return (FALSE);
	node = malloc(sizeof(StackNode));
	if (!node)
		return (FALSE);
	*node = element;
	node->pLink = pStack->pTopElement;
	pStack->pTopElement = node;
	pStack->currentElementCount += 1;
	return (TRUE);
}

StackNode	*popLS(LinkedStack *pStack)
{
	StackNode	*rt_node;

	if (!pStack || !(pStack->currentElementCount))
		return (FALSE);
	rt_node = pStack->pTopElement;
	pStack->pTopElement = pStack->pTopElement->pLink;
	// free (rt_node);
	pStack->currentElementCount -= 1;
	return (rt_node);
}

StackNode	*peekLS(LinkedStack *pStack)
{
	if (!pStack || !(pStack->currentElementCount))
		return (FALSE);
	return (pStack->pTopElement);
}

void	deleteLinkedStack(LinkedStack *pStack)
{
	int	crnt;

	if (!pStack || !(pStack->pTopElement))
	{
		free (pStack);
		return ;
	}
	crnt = pStack->currentElementCount;
	while (crnt--)
		popLS(pStack);
	free (pStack);
}

int	isLinkedStackEmpty(LinkedStack *pStack)
{
	if (pStack
		&& pStack->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}
