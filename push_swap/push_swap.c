#include "push_swap.h"

int	main(int argc, char **argv)
{
	LinkedStack	*pStackA;
	LinkedStack	*pStackB = createLinkedStack();
	int			num;
	int			chunk;
	int			*arr;

	ft_printf("argc : %d\n", argc - 1);
	if (argc < 2)
		return (0);
	num = 0;
	chunk = 15;
	if (argc - 1 == 500)
		chunk = 30;
	arr = parsing(argc - 1, argv);
	pStackA = create_pStackA(arr, argc - 1);
	StackNode *nodeA = pStackA->pTopElement;
	for (int i = 0; i < argc - 1; i++)
	{
		int d = nodeA->index;
		ft_printf("%d : ", d);
		while (d--)
			ft_printf(".");
		ft_printf("\n");
		nodeA = nodeA->pLink;
	}
	// StackNode	*nodeA = pStackA->pTopElement;
	// while (nodeA)
	// {
	// 	printf("index : %d\n", nodeA->index);
	// 	nodeA = nodeA->pLink;
	// }
	ft_printf("\nA crnt cnt : %d\n", pStackA->currentElementCount);
	move_pStackA_to_pStackB(pStackA, pStackB, 15);
	ft_printf("\nB crnt cnt : %d\n", pStackB->currentElementCount);
	StackNode *nodeB = pStackB->pTopElement;
	for (int i = 0; i < argc - 1; i++)
	{
		int d = nodeB->index;
		ft_printf("%d : ", d);
		while (d--)
			ft_printf(".");
		ft_printf("\n");
		nodeB = nodeB->pLink;
	}
	// while (nodeB)
	// {
	// 	printf("index : %d\n", nodeB->index);
	// 	nodeB = nodeB->pLink;
	// }
	move_pStackB_to_pStackA(pStackA, pStackB);
	nodeA = pStackA->pTopElement;
	for (int i = 0; i < argc - 1; i++)
	{
		int d = nodeA->index;
		ft_printf("%d : ", d);
		while (d--)
			ft_printf(".");
		ft_printf("\n");
		nodeA = nodeA->pLink;
	}
	deleteLinkedStack(pStackA);
	deleteLinkedStack(pStackB);
	// system("leaks a.out");
	return (0);
}
