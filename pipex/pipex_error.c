/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:50:36 by jislim            #+#    #+#             */
/*   Updated: 2022/06/20 09:51:07 by jislim           ###   ########.fr       */
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
