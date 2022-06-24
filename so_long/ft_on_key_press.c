/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_key_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:01:59 by jislim            #+#    #+#             */
/*   Updated: 2022/06/24 10:05:16 by jislim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	on_key_press(int keycode, t_location *location)
{
	if (keycode == KEY_W)
		location->player_height++;
	else if (keycode == KEY_A)
		location->player_width--;
	else if (keycode == KEY_S)
		location->player_height--;
	else if (keycode == KEY_D)
		location->player_width++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", location->player_width, location->player_height);
	return (0);
}
