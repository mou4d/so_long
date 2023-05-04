/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 23:42:23 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/04 16:27:24 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
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
	if (keycode != 0 && e != NULL)
	{
		ft_printf("%d\n", keycode);
		mlx_clear_window(e->mlx, e->win);
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
	// mlx_key_hook(e->win, on_key_click, e);
	// c_img = mlx_xpm_file_to_image(e->mlx, "./xpms/c_pumpkin.xpm",
	// 		&c_img_w, &c_img_h);
	// mlx_put_image_to_window(e->mlx, e->win, c_img, 10, 18);
	// mlx_put_image_to_window(e->mlx, e->win, c_img, 80, 80);
	// mlx_put_image_to_window(e->mlx, e->win, c_img, 1000, 500);
	// mlx_put_image_to_window(e->mlx, e->win, c_img, 25, 50);
	// mlx_put_image_to_window(e->mlx, e->win, c_img, 450, 180);
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

int main(int argc, char **argv)
{
	t_map	*map;
	
	if (argc > 1)
	{
		map = read_map(argv[1]);
		map = process_map(map);
		ft_printf("\n### Map details ###\n");
		ft_printf("Map Width %d", map->map_width);
		ft_printf(" Map Height %d\n", map->map_height);
		ft_printf("player : x %d", map->player.x);
		ft_printf(" | y %d\n", map->player.y);
		ft_printf("Exit   : x %d", map->exit.x);
		ft_printf(" | y %d\n\n", map->exit.y);
		int i = 0;
		while (map->map[i])
			ft_printf("%s\n", map->map[i++]);
		ft_printf("\nmap->is_valid = %d\n", map->is_valid);
	}
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
// 	mlx.player.x = 30;
// 	mlx.player.y = 30;
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.player.img, 30, 30);
// 	// // mlx_clear_window(mlx.mlx, mlx.win);
// 	// mlx_put_image_to_window(mlx.mlx, mlx.win, img, 50, 5);
// 	mlx_hook(mlx.win, 2, 0, on_esc_click, &mlx);
// 	mlx_hook(mlx.win, 17, 0, on_window_destroy, &mlx);
// 	mlx_key_hook(mlx.win, on_key_click, &mlx);
// 	mlx_loop_hook(mlx.mlx, next_frame, &mlx);
// 	mlx_loop(mlx.mlx);
// }
