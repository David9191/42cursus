/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:56:28 by jislim            #+#    #+#             */
/*   Updated: 2022/07/26 11:56:36 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	env(t_minishell *data)
{
	int		i;
	char	**dest;

	dest = data->new_env;
	i = 0;
	while (dest[i])
	{
		if (ft_strchr(dest[i], '='))
			ft_putendl_fd(dest[i], 1);
		i++;
	}
	exit(0);
}
