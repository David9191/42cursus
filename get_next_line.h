/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:38 by jislim            #+#    #+#             */
/*   Updated: 2021/12/20 01:14:23 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// # ifndef OPEN_MAX
// #  define OPEN_MAX 256
// # endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif


char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*cpy_edl(char *str);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
