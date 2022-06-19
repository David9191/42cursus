/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:38:49 by jislim            #+#    #+#             */
/*   Updated: 2022/06/19 00:47:18 by jislim           ###   ########.fr       */
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
char	**make_paths(char **envp);
int		check_cmd_accessible(char *cmd);
void	excute_cmd(char *argv, char **envp);
void	parent_process(int *pipe_fd, char **argv, char **envp, pid_t pid);
void	child_process(int *pipe_fd, char **argv, char **envp);
void	free_double_pointer(char **double_pointer);
void	argv_error_exit(char *error_message);

# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0

# define STDIN_FD		0
# define STDOUT_FD		1
# define STDERR_FD		2

# define READ_FD		0
# define WRITE_FD		1

# define IS_PERROR		1

# define NULL_P			((void *)0)

#endif
