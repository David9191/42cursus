/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:05:00 by jislim            #+#    #+#             */
/*   Updated: 2022/06/22 15:56:58 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *str)
{
	if (str)
		write(2, str, ft_strlen(str));
	exit(1);
}


int	on_key_press(int keycode, t_coordinate *coordinate)
{
	if (keycode == KEY_W)
		coordinate->y++;
	else if (keycode == KEY_A)
		coordinate->x--;
	else if (keycode == KEY_S)
		coordinate->y--;
	else if (keycode == KEY_D)
		coordinate->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", coordinate->x, coordinate->y);
	return (0);
}

t_images_paths	*images_init(void)
{
	t_images_paths	*images;

	images = malloc(sizeof(t_images_paths) * 1);
	if (!images)
		error_exit("Error\n");
	images->img_width = 0;
	images->img_height = 0;
	images->wall = ft_strdup("./images/wall.xpm");
	images->land = ft_strdup("./images/land.xpm");
	images->character = ft_strdup("./images/character.xpm");
	images->item = ft_strdup("./images/item.xpm");
	images->exit = ft_strdup("./images/exit.xpm");
	return (images);
}

char	**make_map(void)
{
	char	**map = malloc(sizeof(char *) * 5);

	for (int idx = 0; idx < 5; idx++)
		map[idx] = malloc(sizeof(char) * 13);
	map[0] = ft_memcpy(map[0], "1111111111111", 13);
	map[1] = ft_memcpy(map[1], "10010000000C1", 13);
	map[2] = ft_memcpy(map[2], "1000011111001", 13);
	map[3] = ft_memcpy(map[3], "1P0011E000001", 13);
	map[4] = ft_memcpy(map[4], "1111111111111", 13);
	return (map);
}

int	main(void)
{
	char			**map = make_map();
	t_game			*game = malloc(sizeof(t_game));
	t_coordinate	coordinate;
	t_images_paths	*images;
	void			*img[5];
	
	images = images_init();
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1920, 1080, "my_mlx");
	img[0] = mlx_xpm_file_to_image(game->mlx_ptr, images->character, &images->img_width, &images->img_height);
	img[1] = mlx_xpm_file_to_image(game->mlx_ptr, images->wall, &images->img_width, &images->img_height);
	img[2] = mlx_xpm_file_to_image(game->mlx_ptr, images->land, &images->img_width, &images->img_height);
	img[3] = mlx_xpm_file_to_image(game->mlx_ptr, images->item, &images->img_width, &images->img_height);
	img[4] = mlx_xpm_file_to_image(game->mlx_ptr, images->exit, &images->img_width, &images->img_height);
	fill_images(map, img, game);
	mlx_hook(game->win_ptr, X_EVENT_KEY_RELEASE, 0, &on_key_press, &coordinate);
	mlx_loop(game->mlx_ptr);
}