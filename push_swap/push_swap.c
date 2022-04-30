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
	if (argc == 500)
		chunk = 30;
	arr = parsing(argc - 1, argv);
	// for (int i = 0; i < argc - 1; i++)
	// 	ft_printf("%d | ", arr[i]);
	pStackA = pStackA_indexing(arr, argc - 1);
	ft_printf("\nA crnt cnt : %d\n", pStackA->currentElementCount);
	// for (int i = 0; pStackA->pTopElement; i--)
	// 	ft_printf("pStackA's TOP DATA : %d\n", popLS(pStackA));
	move_pStackA_to_pStackB(pStackA, pStackB, 15);
	ft_printf("\nB crnt cnt : %d\n", pStackB->currentElementCount);
	// for (int i = pStackB->currentElementCount; i; i--)
	// 	ft_printf("pStackB's TOP DATA : %d\n", popLS(pStackB));
	for (int i = 0; i < argc - 1; i++)
	{
		int d = popLS(pStackB);
		ft_printf("%d : ", d);
		for (; d; d--)
			ft_printf("|");
		ft_printf("\n");	
	}	
	return (0);
}
