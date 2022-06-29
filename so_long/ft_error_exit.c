/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:48:11 by jislim            #+#    #+#             */
/*   Updated: 2022/06/29 20:26:31 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	error_exit(char *str)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	if (str)
		write(2, str, ft_strlen(str));
	exit(1);
}

int	mlx_destroy_notify(void)
{
	exit(0);
	return (0);
}

char	*check_argv(char *argv)
{
	char	**str;

	str = ft_split(argv, '.');
	if (!str || !str[1] || str[2] \
		|| ft_strncmp(str[1], "ber", ft_strlen(str[1])))
		error_exit("invalid file extension");
	else
		ft_double_free(str);
	return (argv);
}
