/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 23:42:23 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/04/28 14:28:47 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "_mlx.h"
#include <stdio.h>

int	on_esc_click(int keycode, t_mlx *e)
{
	if (keycode == ESC && e != NULL)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	return (0);
}

void	move_player(int keycode, t_player *player)
{
	int	curr_pos_x;
	int	curr_pos_y;

	curr_pos_x = player->x;
	curr_pos_y = player->y;
	if (keycode == UP_ARROW && curr_pos_y > 0)
		player->y -= 80;
	else if (keycode == DOWN_ARROW && curr_pos_y < WIN_HEIGHT)
		player->y += 80;
	else if (keycode == LEFT_ARROW && curr_pos_x > 0)
		player->x -= 80;
	else if (keycode == RIGHT_ARROW && curr_pos_x < WIN_WIDTH)
		player->x += 80;
	ft_printf("x %d\ty %d\n", player->x, player->y);
}

int	on_key_click(int keycode, t_mlx *e)
{
	if (keycode != 0 && e != NULL)
	{
		ft_printf("%d\n", keycode);
		mlx_clear_window(e->mlx, e->win);
		// mlx_destroy_image(e->mlx, e->player.img);
		move_player(keycode, &e->player);
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
	void	*c_img;
	int		c_img_w;
	int		c_img_h;
	// mlx_key_hook(e->win, on_key_click, e);
	c_img = mlx_xpm_file_to_image(e->mlx, "./xpms/c_pumpkin.xpm",
			&c_img_w, &c_img_h);
	mlx_put_image_to_window(e->mlx, e->win, c_img, 10, 18);
	mlx_put_image_to_window(e->mlx, e->win, c_img, 80, 80);
	mlx_put_image_to_window(e->mlx, e->win, c_img, 1000, 500);
	mlx_put_image_to_window(e->mlx, e->win, c_img, 25, 50);
	mlx_put_image_to_window(e->mlx, e->win, c_img, 450, 180);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc > 1)
		printf("%d\n", map_check(argv[1]));
	return 0;
}

// int	main(void)
// {
// 	t_mlx	mlx;
// 	int		img_w;
// 	int		img_h;

// 	mlx.mlx = mlx_init();
// 	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Soooooo long");
// 	mlx.player.img = mlx_xpm_file_to_image(mlx.mlx, "./xpms/ghost_80x80.xpm",
// 			&img_w, &img_h);
// 	mlx.player.x = 0;
// 	mlx.player.y = 0;
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.player.img, 0, 0);
// 	// // mlx_clear_window(mlx.mlx, mlx.win);
// 	// mlx_put_image_to_window(mlx.mlx, mlx.win, img, 50, 5);
// 	mlx_hook(mlx.win, 2, 0, on_esc_click, &mlx);
// 	mlx_hook(mlx.win, 17, 0, on_window_destroy, &mlx);
// 	mlx_key_hook(mlx.win, on_key_click, &mlx);
// 	mlx_loop_hook(mlx.mlx, next_frame, &mlx);
// 	mlx_loop(mlx.mlx);
// }
