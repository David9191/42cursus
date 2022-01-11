/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:47 by jislim            #+#    #+#             */
/*   Updated: 2022/01/12 02:43:11 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 18765

// 21234

// 38765

// 41234

// 58765

char	*get_line(int fd, char *backup)
{
	char	*buf;
	int		check_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	check_read = 1;
	// printf("backup : %s\n", backup);
	// 오랜만
	while (!ft_strchr(backup, '\n') && check_read != 0)
	{
		check_read = read(fd, buf, BUFFER_SIZE);
		if ((check_read == 0 && !buf) || check_read < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[check_read] = '\0';
		backup = ft_strjoin(backup, buf);
	}
	// printf("backup : %s\n", backup);
	free(buf);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = get_line(fd, backup);
	if (!backup)
		return (NULL);
	// printf("backup : %s", backup);
	buf = get_line_endl(backup);
	backup = save_backup(backup);
	if (backup == NULL)
		return (NULL);
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
		printf("%s", buf);
		free(buf);
	}
}
