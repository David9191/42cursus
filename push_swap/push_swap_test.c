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

	system("leaks a.out | grep leaked");
}
