/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 23:42:23 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/06 19:44:44 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_map	*map;

	if (argc > 1)
	{
		map = read_map(argv[1]);
		process_map(map);
		ft_printf("\n### Map details ###\n");
		ft_printf("Map Width %d", map->map_width);
		ft_printf(" Map Height %d\n", map->map_height);
		ft_printf("player : x %d", map->player.x);
		ft_printf(" | y %d\n", map->player.y);
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
// 	int		window_width;
// 	int 	window_hight;

	
// 	mlx.mlx = mlx_init();
// 	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Soooooo long");
// 	mlx.player.img = mlx_xpm_file_to_image(mlx.mlx, "./xpms/ghost_right.xpm",
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
