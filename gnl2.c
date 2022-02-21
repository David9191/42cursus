/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:11:31 by jislim            #+#    #+#             */
/*   Updated: 2022/02/21 01:33:45 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl2.h"

char *read_save(int fd, char *backup)
{
	char	*buf;
	int		read_bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(backup, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		backup = ft_strjoin(backup, buf);
	}
	free(buf);
	return (backup);
}

char *get_next_line(int fd)
{
	static char	*backup;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = read_save(fd, backup);
	if (!backup)
		return (NULL);
	buf = get_line(backup);
	backup = save(backup);
	return (buf);
}
