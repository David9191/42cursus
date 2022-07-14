/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuhan <seuhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:46:29 by seuhan            #+#    #+#             */
/*   Updated: 2022/07/14 03:28:11 by seuhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_in_env(t_minishell *data, char *arg)
{
	int		i;
	char	**split;

	split = ft_split(arg, '=');
	i = 0;
	while (data->new_env[i])
	{
		if ((!ft_strncmp(data->new_env[i], split[0], ft_strlen(split[0])) \
		&& data->new_env[i][ft_strlen(split[0])] == '=')
		|| (!ft_strncmp(data->new_env[i], split[0], ft_strlen(split[0])) \
		&& data->new_env[i][ft_strlen(split[0])] == '\0'))
		{
			ft_free_split(split);
			return (1);
		}
		i++;
	}
	ft_free_split(split);
	return (0);
}
