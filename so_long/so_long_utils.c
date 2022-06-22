/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:08:57 by jislim            #+#    #+#             */
/*   Updated: 2022/06/22 20:30:47 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_images(char *map[], t_images *images, t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
		{
			if (map[height][width] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,images->wall, width * 64, height * 64);
			else if (map[height][width] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images->land, width * 64, height * 64);
			else if (map[height][width] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images->character, width * 64, height * 64);
			else if (map[height][width] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images->item, width * 64, height * 64);
			else if (map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images->exit, width * 64, height * 64);
			width++;
		}
		height++;
	}
	return (1);
}