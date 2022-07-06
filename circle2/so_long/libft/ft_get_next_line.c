/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:47 by jislim            #+#    #+#             */
/*   Updated: 2022/06/28 10:19:01 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line(int fd, char *backup)
{
	char	*buf;
	int		check_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	check_read = 1;
	while (!ft_strchr_gnl(backup, '\n') && check_read != 0)
	{
		check_read = read(fd, buf, BUFFER_SIZE);
		if (check_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[check_read] = '\0';
		backup = ft_strjoin_gnl(backup, buf);
	}
	free(buf);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;

	if (fd == -1 || BUFFER_SIZE < 0)
		return (NULL);
	backup = get_line(fd, backup);
	if (!backup)
		return (NULL);
	buf = get_line_endl(backup);
	backup = save_backup(backup);
	return (buf);
}
