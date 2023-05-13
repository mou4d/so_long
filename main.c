/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 23:42:23 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/11 16:49:15 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_images(t_map *map, void *mlx_ptr)
{
	int	img_w;
	int	img_h;

	map->collectible.image = mlx_xpm_file_to_image(mlx_ptr,
			"textures/pumpkin_32x32.xpm", &img_w, &img_h);
	map->wall.image = mlx_xpm_file_to_image(mlx_ptr,
			"./textures/wall_square_32x32.xpm", &img_w, &img_h);
	map->player.image = mlx_xpm_file_to_image(mlx_ptr,
			"./textures/ghost_32x32.xpm", &img_w, &img_h);
	map->exit.image = mlx_xpm_file_to_image(mlx_ptr,
			"./textures/floor-portal.xpm", &img_w, &img_h);
}

void	register_handlers(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 0, on_esc_click, mlx);
	mlx_hook(mlx->win, 17, 0, on_window_destroy, mlx);
	mlx_key_hook(mlx->win, on_key_click, mlx);
}

void	init_mlx(t_mlx *mlx, t_map *map)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx,
			map->map_width * 32, map->map_height * 32, "L'Ghost Dokkali");
	init_map_images(map, mlx->mlx);
	mlx->map = map;
	map->mv_count = 0;
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_map	*map;

	if (ac > 1)
	{
		map = read_map(av[1]);
		if (map != NULL && validate_map(map))
		{
			init_mlx(&mlx, map);
			put_on_screen(&mlx, map->map_copy);
			register_handlers(&mlx);
			mlx_loop(mlx.mlx);
			return (0);
		}
		else
		{
			ft_printf("Map Error, check your map and try again !\n");
			free_exit(&mlx, 1);
		}
	}
	ft_printf("usage : so_long <mapfile.ber>\n");
	return (1);
}
