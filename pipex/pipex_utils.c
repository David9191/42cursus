/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:29:55 by jislim            #+#    #+#             */
/*   Updated: 2022/06/17 19:11:43 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *error_message, int is_perror)
{
	if (is_perror)
		perror(error_message);
	else
		write(2, error_message, ft_strlen(error_message));
	exit(1);
}

char	**make_paths_added_slash(char **paths)
{
	char	**new_paths;
	int		idx;

	idx = 0;
	if (!paths)
		error_exit("ERROR_MAKE_PATHS_SLASH", !IS_PERROR);
	new_paths = malloc(sizeof(char *) * (ft_doublep_len(paths) + 1));
	while (paths[idx])
	{
		new_paths[idx] = ft_strjoin(paths[idx], "/");
		idx++;
	}
	new_paths[idx] = NULL;
	free_double_pointer(paths);
	return (new_paths);
}

char	**make_paths(char **envp)
{
	char	**paths;
	int		idx;

	if (!envp)
		error_exit("ERROR_MAKE_PATHS", !IS_PERROR);
	idx = 0;
	while (envp[idx])
	{
		if (ft_strncmp(envp[idx], "PATH", 4) == 0)
		{
			paths = ft_split(envp[idx], ':');
			paths = make_paths_added_slash(paths);
			return (paths);
		}
		idx++;
	}
	error_exit("ERROR_PATHS", !IS_PERROR);
}

void	check_cmd_accessible(char *path, char *cmd);

void	excute_cmd(char **argv, char **envp)
{
	char	**paths;

	if (argv && envp)
	{
		paths = make_paths(envp);
		check_cmd_accessible(paths, argv[2]);
	}
}




















void	parent_process(int *pipe_fd, char **argv, char **envp);
void	child_process(int *pipe_fd, char **argv, char **envp);

void	free_double_pointer(char **double_pointer)
{
	int	idx;

	if (double_pointer)
	{
		idx = 0;
		while (double_pointer[idx])
		{
			free(double_pointer[idx]);
			idx++;
		}
		free(double_pointer);
	}
	error_exit("NOT_APPROPRIATE_ARG", !IS_PERROR);
}

void	argv_error_exit(char *error_message);

