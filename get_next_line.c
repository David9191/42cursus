/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:47 by jislim            #+#    #+#             */
/*   Updated: 2021/12/25 03:43:12 by jislim           ###   ########.fr       */
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
		// printf("backup : %s\n", backup);
	}
	ret_buf = backup;
	// printf("ret_buf : %s\n", ret_buf);
	return (ret_buf);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	backup = malloc(sizeof(char) * BUFFER_SIZE + 1);
	backup = get_line(fd, backup);
	// printf("backup : %s\n", backup); // 전체 다 들어옴.
	if (!backup)
		return (NULL);
	buf = get_line_endl(backup);
	// printf("backup : %s\n", backup); 전체 다 유지.
	// printf("buf : %s\n", buf);
	backup = save_backup(backup);
	printf("backup : %s\n", backup);
	return (buf);
}

int	main(void)
{
	char	*buf = "\n";
	int		fd;
	int		cnt = 3;

	fd = open("hello.txt", O_RDWR);
	while (cnt--)
	{
		buf = get_next_line(fd);
		if (!ft_strlen(buf))
			break ;
		printf("%s\n", buf);
		free(buf);
	}
}
