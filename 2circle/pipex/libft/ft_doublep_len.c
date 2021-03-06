/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublep_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:51:02 by jislim            #+#    #+#             */
/*   Updated: 2022/06/17 20:59:57 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_doublep_len(char **dp)
{
	int	len;

	if (!dp)
		return (-1);
	len = 0;
	while (dp[len])
		len++;
	return (len);
}
