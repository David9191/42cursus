/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:10:03 by taeheonk          #+#    #+#             */
/*   Updated: 2022/06/27 15:57:52 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static	int	get_map_height(char *map_dir)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(map_dir, O_RDONLY);
	if (fd == -1)
		error_exit("open");
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL_FD)
			break ;
		height++;
	}
	close(fd);
	return (height);
}

static	void	set_map(char *map_dir, t_map_info *map_info)
{
	int		fd;
	char	*line;
	char	**map;

	fd = open(map_dir, O_RDONLY);
	if (fd == -1)
		error_exit("open");
	map = map_info->map;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL_FD)
			break ;
		*(map) = line;
		map++;
	}
	map_info->map[map_info->height] = NULL;
}

static	void	set_characters(t_map_info *map_info)
{
	int		idx;
	int		k;
	char	**map;
	int		height;

	map = (map_info->map);
	height = (map_info->height);
	idx = 0;
	while (idx < height)
	{
		k = 0;
		while (map[idx][k] != '\0')
		{
			if (map[idx][k] == 'C')
				(map_info->characters->c_number)++;
			else if (map[idx][k] == 'P')
			{
				(map_info->characters->p_number)++;
				map_info->location->player_height = idx;
				map_info->location->player_width = k;
			}
			else if (map[idx][k] == 'E')
				(map_info->characters->e_number)++;
			k++;
		}
		idx++;
	}
}

static	void	trim_new_line(t_map_info *map_info)
{
	char	**map;
	int		idx;
	int		k;

	map = map_info->map;
	idx = 0;
	while (map[idx])
	{
		k = 0;
		while (map[idx][k])
		{
			if (map[idx][k] == '\n')
				map[idx][k] = '\0';
			k++;
		}
		idx++;
	}
}

void	parse_map(char *map_dir, t_map_info *map_info)
{
	map_info->height = get_map_height(map_dir);
	map_info->map = malloc(sizeof(char **) * ((map_info->height) + 1));
	if (!(map_info->map))
		error_exit("malloc\n");
	set_map(map_dir, map_info);
	trim_new_line(map_info);
	map_info->width = ft_strlen(*(map_info->map));
	set_characters(map_info);
}
