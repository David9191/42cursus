/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:38:49 by jislim            #+#    #+#             */
/*   Updated: 2022/07/06 11:49:00 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

void	excute_cmd(char *argv, char **envp);
void	error_exit(char *error_message, int is_perror);

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
