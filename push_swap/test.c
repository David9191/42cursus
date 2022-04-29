#include "push_swap.h"

int	main(int argc, char **argv)
{
	// in case : s 1 2 3 4 5
	ft_printf("argc : %d\n", argc); // argc == 6
	for (size_t i = 0; argv[i]; i++)
		ft_printf("argv[%d] : %s\n", i, argv[i]);
}
