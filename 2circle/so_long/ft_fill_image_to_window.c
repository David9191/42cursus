/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_image_to_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:08:10 by jislim            #+#    #+#             */
/*   Updated: 2022/06/28 19:29:55 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	put_image_to_window(t_game *game, t_images *images,
		t_map_info *map_info, char separator)
{
	if (separator == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			images->wall, 50 * map_info->width, 50 * map_info->height);
	else if (separator == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			images->land, 50 * map_info->width, 50 * map_info->height);
	else if (separator == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			images->character, 50 * map_info->width, 50 * map_info->height);
	else if (separator == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			images->item, 50 * map_info->width, 50 * map_info->height);
	else if (separator == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			images->exit, 50 * map_info->width, 50 * map_info->height);
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
