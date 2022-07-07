/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:40:41 by jislim            #+#    #+#             */
/*   Updated: 2022/06/19 00:47:13 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_pro(int *pipe_fd, char **argv, char **envp)
{
	int	infile;

	if (access("inflie", F_OK | R_OK) == 1) // 굳이 필요한 애일까?
		error_exit("access", 0);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		error_exit("open", IS_PERROR);
	if (dup2(infile, STDIN_FILENO) == -1)
		error_exit("dup2", IS_PERROR);
	if (dup2(pipe_fd[WRITE_FD], STDOUT_FILENO) == -1)
		error_exit("dup2", IS_PERROR);
	if (close(pipe_fd[READ_FD]) == -1 || close(pipe_fd[WRITE_FD]) == -1)
		error_exit("close", IS_PERROR);
	make_stream(argv[2], envp);
}

void	parent_pro(int *pipe_fd, char **argv, char **envp, int pid)
{
	int	outfile;

	if (waitpid(pid, NULL, 0) == -1)
		error_exit("waitpid", 0);
	if (access("outfile", F_OK | W_OK) == 1) // 굳이 필요한 애일까?
		error_exit("access", IS_PERROR);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error_exit("open", IS_PERROR);
	if (dup2(pipe_fd[READ_FD], STDIN_FILENO) == -1)
		error_exit("dup2", IS_PERROR);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error_exit("dup2", IS_PERROR);
	if (close(pipe_fd[READ_FD]) == -1 || close(pipe_fd[WRITE_FD]) == -1)
		error_exit("close", IS_PERROR);
	make_stream(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			error_exit("pipe", IS_PERROR);
		pid = fork();
		if (pid < 0)
			return (1);
		else if (pid == 0)
			child_pro(pipe_fd, argv, envp);
		else
			parent_pro(pipe_fd, argv, envp, pid);
	}
	else
		error_exit("Error: Bad arguments\n", 0);
	return (0);
}
