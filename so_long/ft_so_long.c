/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:05:00 by jislim            #+#    #+#             */
/*   Updated: 2022/06/29 20:35:31 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	main(int argc, char **argv)
{
	t_map_info	*map_info;
	char		*map_dir;

	if (argc == 2 && ft_strlen(argv[1]) != 0)
	{
		map_dir = check_argv(argv[1]);
		map_info = init_map();
		parse_map(map_dir, map_info);
		check_map(map_info);
		map_info->game->mlx_ptr = mlx_init();
		map_info->game->win_ptr = mlx_new_window(map_info->game->mlx_ptr,
				50 * map_info->width, 50 * map_info->height, "so_long");
		map_info->images = create_images(map_info->game);
		fill_images_to_window(map_info, map_info->images, map_info->game);
		mlx_hook(map_info->game->win_ptr, X_EVENT_KEY_PRESS, 0,
			&on_key_press, map_info);
		mlx_hook(map_info->game->win_ptr, DESTROY_NOTIFY, 0,
			&mlx_destroy_notify, NULL_FD);
		mlx_loop(map_info->game->mlx_ptr);
	}
	error_exit("inappropriate argv");
}
