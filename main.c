/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 23:42:23 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/09 12:59:48 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int main(int argc, char **argv)
// {
// 	t_map	*map;

// 	if (argc > 1)
// 	{
// 		map = read_map(argv[1]);
// 		process_map(map);
// 		ft_printf("\n### Map details ###\n");
// 		ft_printf("Map Width %d", map->map_width);
// 		ft_printf(" Map Height %d\n", map->map_height);
// 		ft_printf("player : x %d", map->player.x);
// 		ft_printf(" | y %d\n", map->player.y);
// 		int i = 0;
// 		while (map->map[i])
// 			ft_printf("%s\n", map->map[i++]);
// 		ft_printf("\nmap->is_valid = %d\n", map->is_valid);
// 	}
// 	return 0;
// }

int	main(int ac, char **av)
{
	t_mlx	mlx;
	int		img_w;
	int		img_h;
	// int 	i;
	// int 	j;
	t_map	*map;

	if (ac > 1)
	{
		map = read_map(av[1]);
		validate_map(map);
		if (map != NULL)
		{	
			mlx.mlx = mlx_init();
			mlx.win = mlx_new_window(mlx.mlx, map->map_width * 32, map->map_height * 32, "Soooooo long");
			map->collectible.image = mlx_xpm_file_to_image(mlx.mlx,
					"xpms/pumpkin_32x32.xpm", &img_w, &img_h);
			map->wall.image = mlx_xpm_file_to_image(mlx.mlx,
					"./xpms/wall_square_32x32.xpm", &img_w, &img_h);
			map->player.image = mlx_xpm_file_to_image(mlx.mlx,
					"./xpms/ghost_32x32.xpm", &img_w, &img_h);
			map->exit.image = mlx_xpm_file_to_image(mlx.mlx,
					"./xpms/floor-portal.xpm", &img_w, &img_h);
			mlx.map = map;
			put_on_screen(&mlx, map->map_copy);
			// mlx.player.img = mlx_xpm_file_to_image(mlx.mlx, "./xpms/ghost_32x32.xpm",
			// 		&img_w, &img_h);
			// mlx.player.x = 32;
			// mlx.player.y = 32;
			// mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.player.img, 32, 32);
			// // mlx_clear_window(mlx.mlx, mlx.win);
			// mlx_put_image_to_window(mlx.mlx, mlx.win, img, 50, 5);
			mlx_hook(mlx.win, 2, 0, on_esc_click, &mlx);
			mlx_hook(mlx.win, 17, 0, on_window_destroy, &mlx);
			mlx_key_hook(mlx.win, on_key_click, &mlx);
			// mlx_loop_hook(mlx.mlx, next_frame, &mlx);
			mlx_loop(mlx.mlx);
			return (0);
		}
		else
		{
			ft_printf("Map Error, check your map and try again !\n");
			return (1);
		}
	}
	ft_printf("usage : so_long <mapfile.ber>\n");
	return (1);
}
