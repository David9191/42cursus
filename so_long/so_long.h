/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:04:57 by jislim            #+#    #+#             */
/*   Updated: 2022/06/22 15:38:12 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

typedef struct s_map
{
	int	width;
	int	height;
	int	**map;
	int	movement;
}		t_map;

typedef struct s_coordinate
{
	int	x;
	int	y;
}		t_coordinate;

typedef struct s_images_paths
{
	int		img_width;
	int		img_height;
	char	*wall;
	char	*land;
	char	*character;
	char	*item;
	char	*exit;
}			t_images_paths;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_game;

int	fill_images(char **map, void **images, t_game *game);

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define	NULL_FD	((void *)0)

#endif