/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:24:07 by jislim            #+#    #+#             */
/*   Updated: 2022/06/17 20:57:57 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// STDIN_FD는 클로즈하고 dup(infile_fd)로 된다. 그럼 0번이 infile_fd가 되는 거다.
// 이러면 우리가 읽어들이는 명령을 실행시키면 infile에서 읽어온다.
// STDOUT_FD는 클로즈하고 dup(pipe_fd)로 된다. 그럼 1번이 pipe_fd[1]이 되는 거다.
// 이러면 우리가 쓰기 명령을 실행시키면 pipe에 쓴다.
void	child_process(int *pipe_fd, char **argv, char **envp)
{
	int	infile_fd;

	if (pipe_fd && argv && envp)
	{
		infile_fd = open(argv[1], O_RDONLY);
		if (infile_fd == -1)
			error_exit("open", IS_PERROR);
		if (dup2(infile_fd, STDIN_FD) == -1 || \
			dup2(pipe_fd[WRITE_FD], STDOUT_FD) == -1)
			error_exit("dup2", IS_PERROR);
		if (close(pipe_fd[READ_FD]) == -1 || close(pipe_fd[WRITE_FD]) == -1)
			error_exit("close", IS_PERROR);
		excute_cmd(argv[2], envp);
		error_exit("execve", IS_PERROR);
	}
	error_exit("NOT_APPROPRIATE_ARGS", !IS_PERROR);
}

void	parent_process(int *pipe_fd, char **argv, char **envp, pid_t pid)
{
	int	outfile_fd;

	if (pipe_fd && argv && envp)
	{
		waitpid(pid, NULL, 0);
		outfile_fd = open(argv[4], O_RDONLY | O_CREAT | O_TRUNC, 0777);
		if (outfile_fd == -1)
			error_exit("open", IS_PERROR);
		if (dup2(pipe_fd[READ_FD], STDIN_FD) == -1 || \
			dup2(outfile_fd, STDOUT_FD) == -1)
			error_exit("open", IS_PERROR);
		if (close(pipe_fd[READ_FD]) == -1 || close(pipe_fd[WRITE_FD]) == -1)
			error_exit("close", IS_PERROR);
		excute_cmd(argv[3], envp);
		error_exit("execve", IS_PERROR);
	}
	error_exit("NOT_APPROPRIATE_ARGS", !IS_PERROR);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc == 5 && envp)
	{
		if (pipe(pipe_fd) == -1)
			error_exit("pipe", IS_PERROR);
		pid = fork();
		if (pid == -1)
			error_exit("fork", IS_PERROR);
		else if (pid == 0)
			child_process(pipe_fd, argv, envp);
		else
			parent_process(pipe_fd, argv, envp, pid);
	}
	write(2, "NOT_APPROPRIATE_ARGV", ft_strlen("NOT_APPROPRIATE_ARGV"));
	return (1);
}

// void	error_exit(char *error_message);
// void	make_paths(char **envp);
// void	check_cmd_accessible(char *path, char *cmd);
// void	excute_cmd(char **argv, char **envp);
// void	parent_process(int *pipe_fd, char **argv, char **envp);
// void	free_double_pointer(char **double_pointer);
// void	argv_error_exit(char *error_message);

// # define EXIT_FAILURE	1
// # define EXIT_SUCCESS	0

// # define STDIN_FD		0
// # define STDOUT_FD		1
// # define STDERR_FD		2

// # define READ_FD		0
// # define WRITE_FD		1

// # define NULL_P			((void *)0)