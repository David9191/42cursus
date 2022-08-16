/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:10:03 by taeheonk          #+#    #+#             */
/*   Updated: 2022/08/19 17:36:04 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void set_map_height(t_map_info *map_info, char *map_dir)
{
	int fd;
	int height;
	char *line;

	fd = open(map_dir, O_RDONLY);
	if (fd == -1)
		error_exit("fail open");
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL_FD)
			break;
		free(line);
		height++;
	}
	close(fd);
	map_info->height = height;
	map_info->map = malloc(sizeof(char **) * ((map_info->height) + 1));
	if (!(map_info->map))
		error_exit("malloc\n");
}

static void set_map(char *map_dir, t_map_info *map_info)
{
	int fd;
	int idx;
	char **map;

	fd = open(map_dir, O_RDONLY);
	if (fd == -1)
		error_exit("fail open");
	map = map_info->map;
	idx = 0;
	while (1)
	{
		map[idx] = get_next_line(fd);
		if (map[idx] == NULL_FD)
			break;
		if (map[idx][ft_strlen(map[idx]) - 1] == '\n')
			map[idx][ft_strlen(map[idx]) - 1] = '\0';
		idx++;
	}
	//	if (!map_info->map[idx])
	//	error_exit("empty map");
	map_info->map[map_info->height] = NULL;
	map_info->width = ft_strlen(map_info->map[0]);
}

static void set_characters(t_map_info *map_info, int height, int width)
{
	char **map;

	map = (map_info->map);
	while (height < (map_info->height))
	{
		width = 0;
		while (map[height][width] != '\0')
		{
			if (map[height][width] == 'C')
				(map_info->characters->c_number)++;
			else if (map[height][width] == 'P')
			{
				(map_info->characters->p_number)++;
				map_info->location->player_height = height;
				map_info->location->player_width = width;
			}
			else if (map[height][width] == 'E')
				(map_info->characters->e_number)++;
			width++;
		}
		height++;
	}
}

void parse_map(char *map_dir, t_map_info *map_info)
{
	set_map_height(map_info, map_dir);
	set_map(map_dir, map_info);
	set_characters(map_info, 0, 0);
}
