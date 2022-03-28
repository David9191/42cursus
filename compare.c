/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:17:36 by jislim            #+#    #+#             */
/*   Updated: 2022/03/29 01:41:12 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
	if (hexa[0] == '0')
		hexa = ft_substr(hexa, is_zero(hexa), (ft_strlen(hexa) - is_zero(hexa)));
	hexa = ft_strjoin("0x", hexa);
	return (hexa);
}

int	main(void)
{
	unsigned int	a = 2147483647;
	unsigned int	*b = &a;
	char			*str;
	// printf("%p\n", (void *) -1);
	// printf("%p\n", (void *)1);
	// str = printf_hexa((void *)1);
	printf("%p\n", b);
	str = printf_hexa(b);
	char	*p = str;
	if (str)
		while (*str)
			write(1, str++, 1);
	free(p);
	return (0);
}
