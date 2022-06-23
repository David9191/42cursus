/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:05:00 by jislim            #+#    #+#             */
/*   Updated: 2022/06/23 18:01:01 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static char	**make_map(void)
{
	char	**map = malloc(sizeof(char *) * 6);

	for (int idx = 0; idx < 5; idx++)
		map[idx] = malloc(sizeof(char) * 13);
	map[0] = ft_memcpy(map[0], "1111111111111", 13);
	map[1] = ft_memcpy(map[1], "10010000000C1", 13);
	map[2] = ft_memcpy(map[2], "1000011111001", 13);
	map[3] = ft_memcpy(map[3], "1P0011E000001", 13);
	map[4] = ft_memcpy(map[4], "1111111111111", 13);
	map[5] = NULL;
	return (map);
}

int	main(void)
{
	t_map_info		*map_info = malloc(sizeof(t_map_info));
	map_info->game = malloc(sizeof(t_game));

	map_info->map = make_map();
	map_info->game->mlx_ptr = mlx_init();
	map_info->game->win_ptr = mlx_new_window(map_info->game->mlx_ptr, 50 * 13, 50 * 5, "so_long");
	map_info->images = create_images(map_info->game);
	fill_images_to_window(map_info, map_info->images, map_info->game);
	mlx_hook(map_info->game->win_ptr, X_EVENT_KEY_RELEASE, 0, &on_key_press,
		&map_info->location);
	mlx_loop(map_info->game->mlx_ptr);
}
