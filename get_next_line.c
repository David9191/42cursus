/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:47 by jislim            #+#    #+#             */
/*   Updated: 2021/12/23 20:35:13 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;
	size_t		check_read;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	while (1)
	{
		check_read = read(fd, backup, BUFFER_SIZE);
		if (check_read < 0)
			return (NULL);
		if (ft_strchr(backup, '\n'))
		{
			// split;
			break ;
		}
		else
			continue ;
	}
}
