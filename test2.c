#include <stdio.h>
#include "./push_swap/libft/libft.h"

int main(int argc, char **argv) {
	char	**str = ft_split(argv[1], ' ');;

	// for (int i = 1; i < 2; i++)
	// {
		printf("%s", str[0]);
		printf("s");
		if ((str[0][0] == '+' || str[0][0] == '-')
				&& str[0][1] == '\0')
			printf("OMG\n");
	// }
}
