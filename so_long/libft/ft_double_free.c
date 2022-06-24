/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:47:00 by jislim            #+#    #+#             */
/*   Updated: 2022/06/24 14:22:07 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_double_free(char **ptr)
{
	int	idx;

	idx = 0;
	while (ptr[idx])
	{
		free (ptr[idx]);
		idx++;
	}
	free (ptr);
}
