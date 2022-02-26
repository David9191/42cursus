/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:38:45 by jislim            #+#    #+#             */
/*   Updated: 2022/02/23 00:33:58 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 위에 추가 함수 더 있음.

char	*get_line(int fd, char *backup)
{
	char	*buf;
	int		check_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	// check_read = read(fd, buf, BUFFER_SIZE);
	// if (check_read == 0)
	// {
	// 	free(buf);
	// 	return (NULL);
	// }
	check_read = 1;
	while (!ft_strchr(backup, '\n') && check_read != 0)
	{
		check_read = read(fd, buf, BUFFER_SIZE);
		// printf("%d\n%p\n%d\n", check_read, buf, buf[0]);
		if (check_read == -1)
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
// fd : 3, BUFFER_SIZE = 10
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
// empty line 고치기

// int	main(void)
// {
// 	char	*buf = "start\n";
// 	int		fd;

// 	fd = open("hello.txt", O_RDWR);
// 	while (1)
// 	{
// 		buf = get_next_line(fd);
// 		if (!ft_strlen(buf))
// 			break ;
// 		printf("%s", buf);
// 		free(buf);
// 	}
// }
