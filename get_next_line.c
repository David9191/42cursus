/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:47 by jislim            #+#    #+#             */
/*   Updated: 2021/12/20 23:55:04 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_line(int fd)
{
	char	buf[BUFFER_SIZE];
	char	*ret_str;
	int		read_check;

	read_check = read(fd, buf, BUFFER_SIZE);
	if (read_check == 0 && !ft_strlen(buf))
		return (NULL);
	if (read_check == 0 && ft_strlen(buf))
		return (ft_strdup(buf));
	ret_str = cpy_edl(buf);
	return (ret_str);
}

char	*get_next_line(int fd)
{
	static char	*buf_saver;
	char		*ret_buf;

	printf("21");
	if (fd < 0)
		return (NULL);
	ret_buf = get_line(fd);
	buf_saver = ret_buf;
	if (!ret_buf)
		return (NULL);
	return (buf_saver);
	close(fd);
}

int	main(void)
{
	int		fd = open("hello.txt", O_APPEND);
	write(fd, "OMG", 3);
	char	*str = get_next_line(fd);
	printf("%s\n", str);
}
