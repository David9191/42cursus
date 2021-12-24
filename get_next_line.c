/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:47 by jislim            #+#    #+#             */
/*   Updated: 2021/12/25 02:48:27 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *backup)
{
	char	buf[BUFFER_SIZE + 1];
	char	*ret_buf;
	int		check_read;

	check_read = 1;
	while (!ft_strchr(backup, '\n') && check_read != 0)
	{
		check_read = read(fd, buf, BUFFER_SIZE);
		if (check_read < 0)
			return (NULL);
		buf[check_read] = '\0';
		backup = ft_strjoin(backup, buf);
	}
	ret_buf = backup;
	return (ret_buf);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	backup = malloc(sizeof(char) * BUFFER_SIZE + 1);
	buf = get_line(fd, backup);
	if (!buf)
		return (NULL);
	buf = get_line_endl(buf);
	backup = save_backup(backup);
	return (buf);
}

int	main(void)
{
	char	*buf = "start\n";
	int		fd;

	fd = open("hello.txt", O_RDWR);
	while (1)
	{
		buf = get_next_line(fd);
		if (!ft_strlen(buf))
			break ;
		printf("%s\n", buf);
		free(buf);
	}
}
