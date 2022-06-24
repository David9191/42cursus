/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:03:10 by taeheonk          #+#    #+#             */
/*   Updated: 2022/06/24 19:27:26 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static	void	check_rect(t_map_info *map_info)
{
	int	len;
	int	idx;

	idx = 0;
	while (map_info->map[idx])
	{
		len = ft_strlen(map_info->map[idx]);
		if (len != map_info->width)
			error_exit(NULL_FD);
		idx++;
	}
}

static	void	check_wall(t_map_info *map_info)
{
	int		idx;
	char	**map;
	char	*line;

	idx = 0;
	map = map_info->map;
	while (idx < map_info->height)
	{
		line = *map;
		if (idx == 0 || idx == (map_info->height - 1))
		{
			while (*line != '\n' && *line != '\0')
			{
				if (*line != '1')
					error_exit(NULL_FD);
				line++;
			}
		}
		else
			if (line[0] != '1' || line[map_info->width - 1] != '1')
				error_exit(NULL_FD);
		map++;
		idx++;
	}
}

static	void	check_least(t_characters *characters)
{
	int	c_number;
	int	p_number;
	int	e_number;

	c_number = characters->c_number;
	p_number = characters->p_number;
	e_number = characters->e_number;
	if (c_number < 1 || p_number < 1 || e_number < 1)
		error_exit(NULL_FD);
}

void	check_map(t_map_info *map_info)
{
	check_rect(map_info);
	check_wall(map_info);
	check_least(map_info->characters);
}
