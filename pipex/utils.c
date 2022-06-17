/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:40:44 by jislim            #+#    #+#             */
/*   Updated: 2022/06/17 15:39:56 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	free_paths(char **paths)
{
	int	idx;

	idx = 0;
	while (paths[idx])
		free(paths[idx++]);
	free(paths);
}

char	*check_access(char *cmd, char **envp)
{
	int		idx;
	char	*real_cmd;
	char	*slash_path;
	char	**paths;

	idx = 0;
	while (ft_strnstr(envp[idx], "PATH", 4) == 0)
		idx++;
	paths = ft_split(envp[idx] + 5, ':');

	idx = 0;
	while (paths[idx] != 0)
	{
		slash_path = ft_strjoin(paths[idx], "/");
		real_cmd = ft_strjoin(slash_path, cmd);
		if (access(real_cmd, X_OK) == 0)
		{
			free_paths(paths);
			return (real_cmd);
		}
		free(slash_path);
		free(real_cmd);
		idx++;
	}
	free_paths(paths);
	return (0);
}

void	make_stream(char *cmd, char **envp)
{
	char	**argv;
	char	*real_cmd;

	argv = ft_split(cmd, ' '); // child : "ls -al", parent : "grep pipex"
	real_cmd = check_access(argv[0], envp);
	if (real_cmd == 0)
		error_exit("access");
	execve(real_cmd, argv, envp);
}

int	arg_error(char *error_message)
{
	write(2, error_message, ft_strlen(error_message));
	exit(1);
}
