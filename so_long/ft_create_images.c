/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:35:01 by jislim            #+#    #+#             */
/*   Updated: 2022/06/24 14:21:03 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	*convert_xpm_to_image(t_game *game, t_images *images, char *str)
{
	void	*image;

	image = NULL;
	if (!ft_strncmp("character", str, ft_strlen(str)))
		image = mlx_xpm_file_to_image(game->mlx_ptr, "./images/character.xpm",
				&images->img_width, &images->img_height);
	else if (!ft_strncmp("wall", str, ft_strlen(str)))
		image = mlx_xpm_file_to_image(game->mlx_ptr, "./images/wall.xpm",
				&images->img_width, &images->img_height);
	else if (!ft_strncmp("land", str, ft_strlen(str)))
		image = mlx_xpm_file_to_image(game->mlx_ptr, "./images/land.xpm",
				&images->img_width, &images->img_height);
	else if (!ft_strncmp("item", str, ft_strlen(str)))
		image = mlx_xpm_file_to_image(game->mlx_ptr, "./images/item.xpm",
				&images->img_width, &images->img_height);
	else if (!ft_strncmp("exit", str, ft_strlen(str)))
		image = mlx_xpm_file_to_image(game->mlx_ptr, "./images/exit.xpm",
				&images->img_width, &images->img_height);
	if (image == NULL)
		error_exit("Error mlx_xpm_file_to_image\n");
	return (image);
}

t_images	*create_images(t_game *game)
{
	t_images	*images;

	images = malloc(sizeof(t_images));
	if (images == NULL)
		error_exit("Error malloc\n");
	images->character = convert_xpm_to_image(game, images, "character");
	images->wall = convert_xpm_to_image(game, images, "wall");
	images->land = convert_xpm_to_image(game, images, "land");
	images->item = convert_xpm_to_image(game, images, "item");
	images->exit = convert_xpm_to_image(game, images, "exit");
	return (images);
}

// void	*create_character_image(t_game *game, t_images *images)
// {
// 	void	*character;

// 	character = mlx_xpm_file_to_image(game->mlx_ptr, "./images/character.xpm",
// 			&images->img_width, &images->img_height);
// 	if (character == NULL)
// 		error_exit("Error mlx_xpm_file_to_image\n");
// 	return (character);
// }

// void	*create_wall_image(t_game *game, t_images *images)
// {
// 	void	*wall;

// 	wall = mlx_xpm_file_to_image(game->mlx_ptr, "./images/wall.xpm",
// 			&images->img_width, &images->img_height);
// 	if (wall == NULL)
// 		error_exit("Error mlx_xpm_file_to_image\n");
// 	return (wall);
// }

// void	*create_land_image(t_game *game, t_images *images)
// {
// 	void	*land;

// 	land = mlx_xpm_file_to_image(game->mlx_ptr, "./images/land.xpm",
// 			&images->img_width, &images->img_height);
// 	if (land == NULL)
// 		error_exit("Error mlx_xpm_file_to_image\n");
// 	return (land);
// }

// void	*create_item_image(t_game *game, t_images *images)
// {
// 	void	*item;

// 	item = mlx_xpm_file_to_image(game->mlx_ptr, "./images/item.xpm",
// 			&images->img_width, &images->img_height);
// 	if (item == NULL)
// 		error_exit("Error mlx_xpm_file_to_image\n");
// 	return (item);
// }

// void	*create_exit_image(t_game *game, t_images *images)
// {
// 	void	*exit;

// 	exit = mlx_xpm_file_to_image(game->mlx_ptr, "./images/exit.xpm",
// 			&images->img_width, &images->img_height);
// 	if (exit == NULL)
// 		error_exit("Error mlx_xpm_file_to_image\n");
// 	return (exit);
// }