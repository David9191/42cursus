/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:17:36 by jislim            #+#    #+#             */
/*   Updated: 2022/03/29 18:11:44 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_zero(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] == '0')
		cnt++;
	return (cnt);
}

char	*printf_hexa(void *v_ptr)
{
	unsigned long long	ad;
	int					hexa_idx;
	char				*hexa;
	char				hexa_c;

	// printf("\nhexa : %p\n", v_ptr);
	ad = (unsigned long long)v_ptr;
	hexa = (char *)malloc(sizeof(char) * 17);
	if (!hexa)
		return (NULL);
	hexa_idx = 15;

	while (hexa_idx >= 0)
	{
		hexa_c = (char)(ad % 16);
		if (hexa_c >= 0 && hexa_c < 10)
			hexa[hexa_idx] = hexa_c + '0';
		else if (hexa_c >= 10 && hexa_c < 16)
			hexa[hexa_idx] = (hexa_c - 10) + 'a';
		hexa_idx--;
		ad /= 16;
	}
	hexa[16] = '\0';

	char	*str;
	str = hexa; // 이전 hexa의 메모리 누수가 나지 않기 위함.
	if (hexa[0] == '0')
		hexa = ft_substr(hexa, is_zero(hexa), (ft_strlen(hexa) - is_zero(hexa)));
	hexa = ft_strjoin("0x", hexa);
	free(str);
	return (hexa);
}

// int	main(void)
// {
// 	unsigned int	a = 2147483647;
// 	unsigned int	*b = &a;
// 	char			*str;
// 	// printf("%p\n", (void *) -1);
// 	// printf("%p\n", (void *)1);
// 	// str = printf_hexa((void *)1);
// 	printf("%p\n", b);
// 	str = printf_hexa(b);
// 	char	*p = str;
// 	if (str)
// 		while (*str)
// 			write(1, str++, 1);
// 	free(p);
// 	printf("\n%u\n", -1);
// 	return (0);
// }
