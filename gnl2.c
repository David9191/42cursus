/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:11:31 by jislim            #+#    #+#             */
/*   Updated: 2022/02/19 23:51:53 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl2.h"

char *read_save(int fd, char *backup)
{
	// 50번 따라 치기!!
	// 해보자!
}

char *get_next_line(int fd)
{
	static char	*backup;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_save(fd, backup);
	if (!backup)
		return (NULL);
	buf = get_line(backup);
	backup = save(backup);
	return (backup);
}
