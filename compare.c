/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:17:36 by jislim            #+#    #+#             */
/*   Updated: 2022/03/28 21:24:50 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

char	*printf_hexa(void *v_ptr)
{
	unsigned long long	ad;
	int					hexa_idx;
	char				*hexa;
	char				hexa_c;

	ad = (unsigned long long)v_ptr;
	hexa = (char *)malloc(sizeof(char) * 17);
	if (!hexa)
		return (NULL);
	hexa = ft_memset(hexa, 100, 17);
	hexa_idx = 15;
	while (hexa_idx >= 0 && ad >= 0)
	{
		hexa_c = (char)(ad % 16);
		if (hexa_idx > -1 && hexa_c >= 0 && hexa_c < 10)
			hexa[hexa_idx] = hexa_c + '0';
		else if (hexa_c >= 10 && hexa_c < 16)
			hexa[hexa_idx] = hexa_c - 10 + 'a';
		hexa_idx--;
		ad /= 16;
	}
	hexa[16] = '\0';
	return (hexa);
}

int	main(void)
{
	// unsigned int	a = 2147483647;
	// unsigned int	*b = &a;
	char			*str;

	// printf("%p\n", (void *) -1);
	printf("%p\n", (void *)1);
	str = printf_hexa((void *)1);
	// str = printf_hexa((void *) -1);
	char	*p = str;
	if (str)
	{
		write(1, "0x", 2);
		while (*str)
		{
			if(*str != 100)
				write(1, str, 1);
			str++;
		}
	}
	free(p);
	return (0);
}
