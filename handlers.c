/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:23:52 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/10 12:45:44 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_esc_click(int keycode, t_mlx *e)
{
	if (keycode == ESC && e != NULL)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	return (0);
}

int	on_key_click(int keycode, t_mlx *e)
{
	if (keycode != 0 && e != NULL)
	{
		mlx_clear_window(e->mlx, e->win);
		move_player_on_map(e, keycode);
		put_on_screen(e, e->map->map_copy);
	}
	return (0);
}

int	on_window_destroy(t_mlx *e)
{
	if (e != NULL)
	{
		free(e->win);
		free(e->mlx);
	}
	exit(0);
}

int	next_frame(t_mlx *e)
{
	void	*wall_img;
	int		wall_img_w;
	int		wall_img_h;
	int		wall_x;
	int		wall_y;

	wall_x = 0;
	wall_img = mlx_xpm_file_to_image(e->mlx, "./xpms/wall_square_32x32.xpm",
			&wall_img_w, &wall_img_h);
	wall_y = wall_img_h;
	while (wall_x <= WIN_WIDTH)
	{
		mlx_put_image_to_window(e->mlx, e->win, wall_img, wall_x, 0);
		mlx_put_image_to_window(e->mlx, e->win, wall_img,
			wall_x, (WIN_HEIGHT - wall_img_h));
		wall_x += wall_img_w;
	}
	while (wall_y <= WIN_HEIGHT)
	{
		mlx_put_image_to_window(e->mlx, e->win, wall_img, 0, wall_y);
		mlx_put_image_to_window(e->mlx, e->win, wall_img,
			(WIN_WIDTH - wall_img_w), wall_y);
		wall_y += wall_img_h;
	}
	return (0);
}
