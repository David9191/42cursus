#include "pipex.h"

void	error_exit(char *error_message, int is_perror)
{
	if (is_perror)
		perror(error_message);
	else
		write(2, error_message, ft_strlen(error_message));
	exit(1);
}

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
			paths = ft_split(envp[idx] + 5, ':');
			paths = make_paths_added_slash(paths);
			return (paths);
		}
		idx++;
	}
	error_exit("ERROR_PATHS", !IS_PERROR);
	return (NULL);
}

int	check_cmd_accessible(char *cmd)
{
	int	idx;
	int	result;

	if (!cmd)
		error_exit("ERROR_CHECK_CMD", !IS_PERROR);
	idx = 0;
	result = access(cmd, X_OK);
	return (result);
}

void	excute_cmd(char *argv, char **envp)
{
	char	**paths;
	int		idx;
	char	**cmd;
	char	*check_cmd;

	if (argv && envp)
	{
		paths = make_paths(envp);
		cmd = ft_split(argv, ' ');
		idx = 0;
		while (paths[idx])
		{
			check_cmd = ft_strjoin(paths[idx], cmd[0]);
			if (check_cmd_accessible(check_cmd) == 0)
				execve(check_cmd, cmd, envp);
			free(check_cmd);
			idx++;
		}
		free_double_pointer(paths);
		error_exit(cmd[0], IS_PERROR);
	}
	error_exit("ERROR_EXCUTE_CMD", !IS_PERROR);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	if (argc > 0 && argv && envp)
// 	{
// 		excute_cmd(argv[2], envp);
// 	}
// }