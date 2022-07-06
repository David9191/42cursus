/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:04:57 by jislim            #+#    #+#             */
/*   Updated: 2022/06/29 15:44:39 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_characters
{
	int	c_number;
	int	p_number;
	int	e_number;
}		t_characters;

typedef struct s_location
{
	int	player_width;
	int	player_height;
}		t_location;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_game;

typedef struct s_images
{
	int		img_width;
	int		img_height;
	void	*character;
	void	*wall;
	void	*land;
	void	*item;
	void	*exit;
}			t_images;

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
	int				*move_cnt;
	t_characters	*characters;
	t_game			*game;
	t_location		*location;
	t_images		*images;
}					t_map_info;

t_images	*create_images(t_game *game);
int			fill_images_to_window(t_map_info *map_info, t_images *images,
				t_game *game);
int			on_key_press(int keycode, t_map_info *map_info);
void		error_exit(char *str);
int			mlx_destroy_notify(void);

void		parse_map(char *map_dir, t_map_info *map_info);
void		check_map(t_map_info *map_info);
t_map_info	*init_map(void);

char		*check_argv(char *argv);

# define X_EVENT_KEY_PRESS			2

# define KEY_ESC					53
# define KEY_W						13
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2

# define DESTROY_NOTIFY				17

# define NULL_FD					((void *)0)

#endif
