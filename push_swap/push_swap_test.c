#include "push_swap.h"

int	main()
{
	LinkedStack	*pStackA = createLinkedStack();
	LinkedStack	*pStackB = createLinkedStack();

	StackNode	nodeA;
	nodeA.data = 65;
	for (size_t i = 0; i < 10; i++)
	{
		nodeA.data++;
		pushLS(pStackA, nodeA);
	}
	StackNode	nodeB;
	nodeB.data = 66;
	for (size_t i = 0; i < 10; i++)
	{
		nodeB.data++;
		pushLS(pStackB, nodeB);
	}
	// ft_printf("stackA : %d\n", pStackA->pTopElement->data);
	// push_swap_sa(pStackA);
	// ft_printf("stackA : %d\n", pStackA->pTopElement->data);
	// ft_printf("stackB : %d\n", pStackB->pTopElement->data);
	// push_swap_sb(pStackB);
	// ft_printf("stackB : %d\n", pStackB->pTopElement->data);
	// ft_printf("stackA : %d\n", pStackA->currentElementCount);
	// ft_printf("stackB : %d\n", pStackB->currentElementCount);
	// ft_printf("stackA : %d\n", pStackA->pTopElement->data);
	// ft_printf("stackB : %d\n", pStackB->pTopElement->data);
	// push_swap_pa(pStackA, pStackB);
	// ft_printf("stackA : %d\n", pStackA->pTopElement->data);
	// ft_printf("stackB : %d\n", pStackB->pTopElement->data);
	// push_swap_pb(pStackA, pStackB);
	// ft_printf("stackA : %d\n", pStackA->pTopElement->data);
	// ft_printf("stackB : %d\n", pStackB->pTopElement->data);
	push_swap_ra(pStackA);
	ft_printf("ra : stackA : %d\n", pStackA->pTopElement->data);
	push_swap_rb(pStackB);
	ft_printf("rb : stackB : %d\n", pStackB->pTopElement->data);
	push_swap_rra(pStackA);
	ft_printf("rra : stackA : %d\n", pStackA->pTopElement->data);
	push_swap_rrb(pStackB);
	ft_printf("rrb : stackB : %d\n", pStackB->pTopElement->data);
	deleteLinkedStack(pStackA);
	deleteLinkedStack(pStackB);
	system("leaks a.out | grep leaked");
}
