#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc != 0)
		ft_printf("make test : %s\n", argv[1]);

	LinkedStack	*pStack = createLinkedStack();
	StackNode	node;
	node.data = 50;
	pushLS(pStack, node);
	ft_printf("pStack's pTopElement : %d\n", popLS(pStack));
	return (0);
}
