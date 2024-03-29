/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:11:50 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/11 14:56:08 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_mlx *mlx, int *x, int *y, char *prev_element)
{
	int	img_size[2];

	mlx_destroy_image(mlx->mlx, mlx->map->player.image);
	mlx->map->player.image = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/ghost_up_32x32.xpm", &img_size[0], &img_size[1]);
	if (mlx->map->map_copy[*y - 1][*x] != '1' && *y > 0)
	{
		mlx->map->map_copy[*y][*x] = *prev_element;
		(*y)--;
		*prev_element = mlx->map->map_copy[*y][*x];
		if (*prev_element != 'E')
			*prev_element = '0';
		if (mlx->map->map_copy[*y][*x] == 'C')
			mlx->map->collectibles_count--;
		mlx->map->map_copy[*y][*x] = 'P';
		mlx->map->mv_count += 1;
		ft_printf("steps : %d\n", mlx->map->mv_count);
	}
}

void	move_down(t_mlx *mlx, int *x, int *y, char *prev_element)
{
	int	img_size[2];

	mlx_destroy_image(mlx->mlx, mlx->map->player.image);
	mlx->map->player.image = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/ghost_down_32x32.xpm", &img_size[0], &img_size[1]);
	if (mlx->map->map_copy[*y + 1][*x] != '1' && *y < mlx->map->map_height - 1)
	{
		mlx->map->map_copy[*y][*x] = *prev_element;
		(*y)++;
		*prev_element = mlx->map->map_copy[*y][*x];
		if (*prev_element != 'E')
			*prev_element = '0';
		if (mlx->map->map_copy[*y][*x] == 'C')
			mlx->map->collectibles_count--;
		mlx->map->map_copy[*y][*x] = 'P';
		mlx->map->mv_count += 1;
		ft_printf("steps : %d\n", mlx->map->mv_count);
	}
}

void	move_right(t_mlx *mlx, int *x, int *y, char *prev_element)
{
	int	img_size[2];

	mlx_destroy_image(mlx->mlx, mlx->map->player.image);
	mlx->map->player.image = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/ghost_32x32.xpm", &img_size[0], &img_size[1]);
	if (mlx->map->map_copy[*y][*x + 1] != '1' && *x < mlx->map->map_width - 1)
	{
		mlx->map->map_copy[*y][*x] = *prev_element;
		(*x)++;
		*prev_element = mlx->map->map_copy[*y][*x];
		if (*prev_element != 'E')
			*prev_element = '0';
		if (mlx->map->map_copy[*y][*x] == 'C')
			mlx->map->collectibles_count--;
		mlx->map->map_copy[*y][*x] = 'P';
		mlx->map->mv_count++;
		ft_printf("steps : %d\n", mlx->map->mv_count);
	}
}

void	move_left(t_mlx *mlx, int *x, int *y, char *prev_element)
{
	int	img_size[2];

	mlx_destroy_image(mlx->mlx, mlx->map->player.image);
	mlx->map->player.image = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/ghost_left_32x32.xpm", &img_size[0], &img_size[1]);
	if (mlx->map->map_copy[*y][*x - 1] != '1' && *x > 0)
	{
		mlx->map->map_copy[*y][*x] = *prev_element;
		(*x)--;
		*prev_element = mlx->map->map_copy[*y][*x];
		if (*prev_element != 'E')
			*prev_element = '0';
		if (mlx->map->map_copy[*y][*x] == 'C')
			mlx->map->collectibles_count--;
		mlx->map->map_copy[*y][*x] = 'P';
		mlx->map->mv_count++;
		ft_printf("steps : %d\n", mlx->map->mv_count);
	}
}

void	move_player_on_map(t_mlx *mlx, int key)
{
	int			x;
	int			y;
	static char	prev_element;

	if (prev_element == 0)
		prev_element = '0';
	get_player_position(mlx->map);
	x = mlx->map->player.x;
	y = mlx->map->player.y;
	if (key == UP_ARROW || key == 14)
		move_up(mlx, &x, &y, &prev_element);
	else if (key == DOWN_ARROW || key == 2)
		move_down(mlx, &x, &y, &prev_element);
	else if (key == RIGHT_ARROW || key == 3)
		move_right(mlx, &x, &y, &prev_element);
	else if (key == LEFT_ARROW || key == 1)
		move_left(mlx, &x, &y, &prev_element);
	mlx->map->player.x = x;
	mlx->map->player.y = y;
	if (mlx->map->collectibles_count == 0 && prev_element == 'E')
		free_exit(mlx, 0);
}
