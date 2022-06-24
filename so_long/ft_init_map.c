/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:04:57 by jislim            #+#    #+#             */
/*   Updated: 2022/06/24 10:55:41 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

t_map_info	*init_map(void)
{
	t_map_info			*map_info;

	map_info = malloc(sizeof(t_map_info));
	if (!map_info)
		error_exit("malloc\n");
	map_info->map = NULL;
	map_info->height = 0;
	map_info->width = 0;
	map_info->characters = malloc(sizeof(t_characters));
	if (!(map_info->characters))
		error_exit("malloc\n");
	map_info->characters->c_number = 0;
	map_info->characters->p_number = 0;
	map_info->characters->e_number = 0;
	map_info->game = malloc(sizeof(t_game));
	if (!(map_info->game))
		error_exit("malloc\n");
	map_info->location = NULL;
	map_info->images = NULL;
	return (map_info);
}
