/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jisung9105@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:01:38 by jislim            #+#    #+#             */
/*   Updated: 2022/03/04 16:08:36 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // for printf function
# include <fcntl.h> // for open function

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char    *get_next_line(int fd);
size_t	ft_strlen(char *s);
size_t	ft_strchr(char *s, int c);
char	*ft_strjoin(char *dest, char *src);
char	*get_line_endl(char *str);
char	*save_backup(char *str);

#endif
