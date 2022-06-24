/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_image_to_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:08:10 by jislim            #+#    #+#             */
/*   Updated: 2022/06/24 09:52:22 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	put_image_to_window(t_game *game, t_images *images,
		t_map_info *map_info, char separator)
{
	if (separator == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			images->wall, map_info->width * 50, map_info->height * 50);
	else if (separator == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			images->land, map_info->width * 50, map_info->height * 50);
	else if (separator == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			images->character, map_info->width * 50, map_info->height * 50);
	else if (separator == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			images->item, map_info->width * 50, map_info->height * 50);
	else if (separator == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			images->exit, map_info->width * 50, map_info->height * 50);
}

int	fill_images_to_window(t_map_info *map_info, t_images *images, t_game *game)
{
	char	**map;

	map = map_info->map;
	map_info->height = 0;
	while (map[map_info->height])
	{
		map_info->width = 0;
		while (map[map_info->height][map_info->width])
		{
			put_image_to_window(game, images, map_info,
				map[map_info->height][map_info->width]);
			map_info->width++;
		}
		map_info->height++;
	}
	return (1);
}
