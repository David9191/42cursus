/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:47:00 by jislim            #+#    #+#             */
/*   Updated: 2022/07/04 10:35:33 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_double_free(char **double_ptr)
{
    int idx;

    if (double_ptr)
    {
        idx = 0;
        while (double_ptr[idx])
        {
            free (double_ptr[idx]);
            idx++;
        }
        free (double_ptr);
        return (0);
    }
    return (-1);
}
