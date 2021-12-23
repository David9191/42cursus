/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:47 by jislim            #+#    #+#             */
/*   Updated: 2021/12/24 01:06:57 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *backup)
{
	char	buf[BUFFER_SIZE + 1];
	char	*ret_buf;
	int		check_read;

	check_read = 1;
	while (!ft_strchr(backup, '\n'))
	{
		check_read = read(fd, buf, BUFFER_SIZE);
		if (check_read < 0)
			return (NULL);
		else if (check_read == 0)
			return (ft_strdup(""));
		buf[BUFFER_SIZE] = '\0';
		ft_strlcat(backup, buf);
	}
	ret_buf = get_line_endl(backup);
	if (!ret_buf)
		return (NULL);
	return (ret_buf);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;
	size_t		check_read;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf = get_line(fd, backup);
	if (!buf)
		return (NULL);
	backup += loc_nl(backup);
	return (buf);
}
