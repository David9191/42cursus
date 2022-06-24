/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:48:11 by jislim            #+#    #+#             */
/*   Updated: 2022/06/24 10:05:14 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	error_exit(char *str)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	if (str)
		write(2, str, ft_strlen(str));
	exit(1);
}
