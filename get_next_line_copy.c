/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jisung9105@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:38:45 by jislim            #+#    #+#             */
/*   Updated: 2022/03/04 15:09:10 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *backup)
{
	char	*buf;
	int		check_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	check_read = 1;
	while (!ft_strchr(backup, '\n') && check_read != 0)
	// \n이 있는 곳까지 또는 '\n'이 없는 경우에는 끝까지 읽겠다.
	{
		check_read = read(fd, buf, BUFFER_SIZE);
		if (check_read == -1) // when return read function -1?
		{
			free(buf);
			return (NULL);
		}
		buf[check_read] = '\0';
		backup = ft_strjoin(backup, buf);
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

int	main(void)
{
	char	*buf = "start\n";
	int		fd;
	int		repeat = 7;

	fd = open("hello.txt", O_RDWR);
	while (repeat--)
	{
		buf = get_next_line(fd);
		if (!ft_strlen(buf))
			break ;
		printf("%s", buf);
		free(buf);
	}
}