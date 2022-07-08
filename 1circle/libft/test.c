/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:55:25 by jislim            #+#    #+#             */
/*   Updated: 2021/12/10 15:30:36 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
// 아토이
	// long long	in = 9223372036854775807;
	// char	*str;
	// for (int i = 0; i < 5000; i++)
	// {
		// str = ft_itoa(in + i);
	// 	if (ft_atoi(str) != atoi(str))
	// 		printf("%s : OMG\n", str);
	// }

	// if (ft_atoi("-2147483649") != atoi("-2147483649"))
	// 	printf(": OMG\n");
	// if (ft_atoi("2147483648") != atoi("2147483648"))
	// 	printf(": OMG\n");
	// if (ft_atoi("9223372036854775807") != atoi("9223372036854775807"))
	// 	printf(": OMG\n");
	// if (ft_atoi("-9223372036854775808") != atoi("-9223372036854775808"))
	// 	printf(": OMG\n");
	// if (ft_atoi("-9223372036854775809") != atoi("-9223372036854775809"))
	// 	printf(": OMG\n");
	// if (ft_atoi("0") != atoi("0"))
	// 	printf(": OMG\n");
	// if (ft_atoi("9223372036854775809") != atoi("9223372036854775809"))
	// 	printf(": OMG\n");

// strcmp 언사인드랑 그냥 캐릭터 차이
	// printf("%d\n", ft_strncmp("\0", "\200", 2));
	// char	a = '\0', b = '\201';
	// unsigned char	a = '\0', b = '\201';
	// if (a > b)
	// 	printf("0\n");
	// else if (a == b)
	// 	printf("==\n");
	// else
	// 	printf("200\n");
	// printf("b : %d\n", b);

// const int *, int const *, int * const difference
	// int a = 5;
	// const int *pa = &a;
	// int	b = 7;
	// int const *pb = &b;

	// int	c = 10;
	// int * const pc = &c;

	// printf("5 : %d\n", *pa);
	// // *pa = 42; read-only
	// pa = &b;
	// printf("7 : %d\n", *pa);

	// printf("7 : %d\n", *pb);
	// // *pb = 42; read-only
	// pb = &a;
	// printf("5 : %d\n", *pb);

	// printf("10 : %d\n", *pc);
	// *pc = 42;
	// // pc = &a; read-only
	// printf("42 : %d\n", *pc);

	// printf("%ld %ld\n", sizeof(size_t), sizeof(unsigned int));

	// memmove
	char* str = "TEST";
	ft_memmove((str + 2), str, 1);

	return 0;
}
