#include "push_swap.h"

int	main(int argc, char **argv)
{
	LinkedStack	*pStackA;
	LinkedStack	*pStackB = createLinkedStack();
	int			chunk;
	t_arr		*s_arr;

	if (argc < 2)
		return (0);
	s_arr = parsing(argv[1]);
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
	move_pStackA_to_pStackB(pStackA, pStackB, 15);
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
