/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:07:52 by jislim            #+#    #+#             */
/*   Updated: 2022/04/03 23:07:01 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_str(char *str)
{
	int	len;

	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	return (len);
}
