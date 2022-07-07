/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:00:39 by jislim            #+#    #+#             */
/*   Updated: 2021/12/07 16:02:16 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL || fd < 0)
		return ;
	if (!ft_strlen(s))
	{
		write(fd, "\n", 1);
		return ;
	}
	i = 0;
	while (s[i] != '\0')
		write(fd, &s[i++], 1);
	write(fd, "\n", 1);
}
