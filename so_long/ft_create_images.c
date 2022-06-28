/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:35:01 by jislim            #+#    #+#             */
/*   Updated: 2022/06/28 12:12:44 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

/*
	mlx_xpm_file_to_image 함수에서 width, height로 넘겨준 포인터에 값을 저장해준다.
	아마도 내부에서 parse_xpm 함수 호출할 때 xpm파일에서 값을 읽어오지 않나 싶다.
*/
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
