/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:50:46 by seuhan            #+#    #+#             */
/*   Updated: 2022/07/14 16:03:02 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_lst_cmd	lst_cmd;
	t_minishell	data;
	int			i;

	if (argc != 1)
		return (0);
	if (!argv)
		return (0);
	if (!env)
		return (0);
	i = -1;
	data.new_env = ft_gc_calloc(ft_destlen(env) + 1, sizeof(char *));
	while (env[++i])
		data.new_env[i] = ft_gc_strdup(env[i]);
	i = find_in_env(&data, "SHLVL");
	data.new_env = replace_exist_line_2(&data,
			data.new_env[i], data.new_env);
	prompt(&lst_cmd, &data);
	return (0);
}
