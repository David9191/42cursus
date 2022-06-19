/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:42:10 by jislim            #+#    #+#             */
/*   Updated: 2022/06/19 00:47:28 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

void	error_exit(char *error_message, int is_perror);
void	free_paths(char **paths);
char	*check_access(char *cmd, char **envp);
void	make_stream(char *cmd, char **envp);
int		arg_error(char *error_message);
void	child_pro(int *fd, char **argv, char **envp);
void	parent_pro(int *fd, char **argv, char **envp, int pid);


# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0

# define FT_NULL	((void *)0)

# define STDIN_FILENO	0
# define STDOUT_FILENO	1
# define STDERR_FILENO	2

# define READ_FD	0
# define WRITE_FD	1

# define IS_PERROR	1
#endif
