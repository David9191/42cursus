/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:03:10 by taeheonk          #+#    #+#             */
/*   Updated: 2022/07/03 00:08:50 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	check_rectangle(t_map_info *map_info)
{
	int	len;
	int	idx;

	idx = 0;
	while (map_info->map[idx])
	{
		len = ft_strlen(map_info->map[idx]);
		if (len != map_info->width)
			error_exit("is not rectangle");
		idx++;
	}
}

static void	check_wall(t_map_info *map_info)
{
	int		height;
	int		width;
	char	**map;

	height = 0;
	map = map_info->map;
	while (height < map_info->height)
	{
		if (height == 0 || height == (map_info->height - 1))
		{
			width = 0;
			while (map[height][width] != '\0')
			{
				if (map[height][width] != '1')
					error_exit("inappropriate wall");
				width++;
			}
		}
		else
			if (map[height][0] != '1' \
				|| map[height][map_info->width - 1] != '1')
				error_exit("inappropriate wall");
		height++;
	}
}

static void	check_least(t_characters *characters)
{
	if (characters->c_number < 1)
		error_exit("inappropriate item");
	if (characters->p_number != 1)
		error_exit("inappropriate player");
	if (characters->e_number < 1)
		error_exit("inappropriate exit");
}

static void	check_invalid_value(t_map_info *map_info)
{
	int		height;
	int		width;
	char	**map;

	height = 0;
	map = map_info->map;
	while (height < map_info->height)
	{
		width = 0;
		while (map[height][width] != '\0')
		{
			if (map[height][width] != '1'
				&& map[height][width] != '0'
				&& map[height][width] != 'C'
				&& map[height][width] != 'E'
				&& map[height][width] != 'P')
				error_exit("invalid value");
			width++;
		}
		height++;
	}
}

void	check_map(t_map_info *map_info)
{
	check_rectangle(map_info);
	check_wall(map_info);
	check_least(map_info->characters);
	check_invalid_value(map_info);
}
