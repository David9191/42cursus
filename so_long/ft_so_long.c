/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:05:00 by jislim            #+#    #+#             */
/*   Updated: 2022/06/24 20:42:47 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	main(int ac, char **av)
{
	t_map_info	*map_info;
	char		*map_dir;

	if (ac == 2)
	{
		// taeheonk
		map_dir = av[1];
		map_info = init_map();
		parse_map(map_dir, map_info);
		check_map(map_info);
		// taeheonk
		map_info->game->mlx_ptr = mlx_init();
		map_info->game->win_ptr = mlx_new_window(map_info->game->mlx_ptr,
				50 * 13, 50 * 5, "so_long");
		map_info->images = create_images(map_info->game);
		fill_images_to_window(map_info, map_info->images, map_info->game);
		mlx_hook(map_info->game->win_ptr, X_EVENT_KEY_RELEASE, 0, &on_key_press,
			&map_info->location);
		mlx_hook(map_info->game->win_ptr, DESTROYNOTIFY, 0, &error_exit,
			"Destroy");
		mlx_loop(map_info->game->mlx_ptr);
	}
}
