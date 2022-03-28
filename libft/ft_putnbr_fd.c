/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:03:14 by jislim            #+#    #+#             */
/*   Updated: 2022/03/28 15:42:42 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_nbr_fd(int n, int fd)
{
	int	p_i;

	p_i = (n % 10) + '0';
	if (n > 9)
		put_nbr_fd((n / 10), fd);
	write(fd, &p_i, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
		put_nbr_fd(n, fd);
	}
	else
		put_nbr_fd(n, fd);
}
