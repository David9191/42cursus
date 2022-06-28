/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_key_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:01:59 by jislim            #+#    #+#             */
/*   Updated: 2022/06/28 12:32:21 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	set_player_location(t_map_info *map_info, int player_height,
		int player_width)
{
	map_info->location->player_height = player_height;
	map_info->location->player_width = player_width;
	(map_info->map)[player_height][player_width] = 'P';
	if ((map_info->map)[player_height + 1][player_width] == 'P')
		(map_info->map)[player_height + 1][player_width] = '0';
	else if ((map_info->map)[player_height - 1][player_width] == 'P')
		(map_info->map)[player_height - 1][player_width] = '0';
	else if ((map_info->map)[player_height][player_width + 1] == 'P')
		(map_info->map)[player_height][player_width + 1] = '0';
	else if ((map_info->map)[player_height][player_width - 1] == 'P')
		(map_info->map)[player_height][player_width - 1] = '0';
	printf("%d\n", (*(map_info->move_cnt))++);
}

static void	re_drow_window(t_map_info *map_info, int player_height,
		int player_width)
{
	char	**map;

	map = map_info->map;
	if (map[player_height][player_width] == '1')
		return ;
	else if (map[player_height][player_width] == '0')
		set_player_location(map_info, player_height, player_width);
	else if (map[player_height][player_width] == 'C')
	{
		map[player_height][player_width] = '0';
		map_info->characters->c_number--;
		set_player_location(map_info, player_height, player_width);
	}
	else if (map[player_height][player_width] == 'E')
	{
		if (map_info->characters->c_number == 0)
		{
			printf("%d\n", (*(map_info->move_cnt))++);
			exit(0);
		}
		else
			return ;
	}
	fill_images_to_window(map_info, (map_info->images), (map_info->game));
}

int	on_key_press(int keycode, t_map_info *map_info)
{
	if (keycode == KEY_W)
		re_drow_window(map_info, (map_info->location->player_height) - 1,
			map_info->location->player_width);
	else if (keycode == KEY_S)
		re_drow_window(map_info, (map_info->location->player_height) + 1,
			map_info->location->player_width);
	else if (keycode == KEY_A)
		re_drow_window(map_info, map_info->location->player_height,
			(map_info->location->player_width) - 1);
	else if (keycode == KEY_D)
		re_drow_window(map_info, map_info->location->player_height,
			(map_info->location->player_width) + 1);
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
