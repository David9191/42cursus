/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:40:41 by jislim            #+#    #+#             */
/*   Updated: 2022/06/17 15:38:23 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_pro(int *pipe_fd, char **argv, char **envp)
{
	int	infile;

	if (access("inflie", F_OK | R_OK) == 1) // 굳이 필요한 애일까?
		error_exit("access");
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		error_exit("open");
	if (dup2(infile, STDIN_FILENO) == -1)
		error_exit("dup2");
	if (dup2(pipe_fd[WRITE_FD], STDOUT_FILENO) == -1)
		error_exit("dup2");
	if (close(pipe_fd[READ_FD]) == -1 || close(pipe_fd[WRITE_FD]) == -1)
		error_exit("close");
	make_stream(argv[2], envp);
}

void	parent_pro(int *pipe_fd, char **argv, char **envp, int pid)
{
	int	outfile;

	if (waitpid(pid, NULL, 0) == -1)
		error_exit("waitpid");
	if (access("outfile", F_OK | W_OK) == 1) // 굳이 필요한 애일까?
		error_exit("access");
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error_exit("open");
	if (dup2(pipe_fd[READ_FD], STDIN_FILENO) == -1)
		error_exit("dup2");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error_exit("dup2");
	if (close(pipe_fd[READ_FD]) == -1 || close(pipe_fd[WRITE_FD]) == -1)
		error_exit("close");
	make_stream(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			error_exit("pipe");
		pid = fork();
		if (pid < 0)
			return (1);
		else if (pid == 0)
			child_pro(pipe_fd, argv, envp);
		else
			parent_pro(pipe_fd, argv, envp, pid);
	}
	else
		arg_error("Error: Bad arguments\n");
	return (0);
}
