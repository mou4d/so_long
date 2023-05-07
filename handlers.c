/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:23:52 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/06 18:37:23 by mbousbaa         ###   ########.fr       */
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

void	move_player(int keycode, t_player *player, int offset)
{
	int	curr_pos_x;
	int	curr_pos_y;

	curr_pos_x = player->x;
	curr_pos_y = player->y;
	if (keycode == UP_ARROW && curr_pos_y > offset)
		player->y -= offset;
	else if (keycode == DOWN_ARROW && curr_pos_y < WIN_HEIGHT)
		player->y += offset;
	else if (keycode == LEFT_ARROW && curr_pos_x > offset)
		player->x -= offset;
	else if (keycode == RIGHT_ARROW && curr_pos_x < WIN_WIDTH)
		player->x += offset;
	ft_printf("x %d\ty %d\n", player->x, player->y);
}

int	on_key_click(int keycode, t_mlx *e)
{
	int		img_w;
	int		img_h;

	if (keycode != 0 && e != NULL)
	{
		mlx_clear_window(e->mlx, e->win);
		if (e->player.img != NULL)
			mlx_destroy_image(e->mlx, e->player.img);
		if (keycode == LEFT_ARROW)
			e->player.img = mlx_xpm_file_to_image(e->mlx,
					"./xpms/ghost_left.xpm", &img_w, &img_h);
		else if (keycode == RIGHT_ARROW)
			e->player.img = mlx_xpm_file_to_image(e->mlx,
					"./xpms/ghost_right.xpm", &img_w, &img_h);
		else if (keycode == UP_ARROW)
			e->player.img = mlx_xpm_file_to_image(e->mlx,
					"./xpms/ghost_up.xpm", &img_w, &img_h);
		else if (keycode == DOWN_ARROW)
			e->player.img = mlx_xpm_file_to_image(e->mlx,
					"./xpms/ghost_down.xpm", &img_w, &img_h);
		move_player(keycode, &e->player, 30);
		mlx_put_image_to_window(e->mlx, e->win, e->player.img,
			e->player.x, e->player.y);
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
	wall_img = mlx_xpm_file_to_image(e->mlx, "./xpms/wall_square_Item_Pack.xpm",
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
