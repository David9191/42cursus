/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putusnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:03:14 by jislim            #+#    #+#             */
/*   Updated: 2022/03/31 23:31:57 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_usnbr_fd(unsigned int n, int fd)
{
	unsigned int	p_i;

	p_i = (n % 10) + '0';
	if (n > 9)
		put_usnbr_fd((n / 10), fd);
	write(fd, &p_i, 1);
}

void	ft_putusnbr_fd(unsigned int n, int fd)
{
	if (fd < 0)
		return ;
	else
		put_usnbr_fd(n, fd);
}
