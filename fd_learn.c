/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_learn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:00:29 by jislim            #+#    #+#             */
/*   Updated: 2022/01/25 18:11:27 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*str;
	int	fd;

	str = malloc(sizeof(char) * 50);
	fd = open("hello.txt", O_RDWR);
	// printf("fd : %d\n", fd);
	write(fd, "HELLO", 5);
	printf("%zd\n", read(fd, str, 50)); // 20
	printf("%zd\n", read(fd, str, 50)); // 0
	printf("%zd\n", read(fd, str, 50)); // 0
	// printf("%s\n", str);
}
