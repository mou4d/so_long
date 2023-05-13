/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:13:03 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/10 12:59:49 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(t_map *map_vars)
{
	int	i;
	int	j;
	int	founded;

	i = -1;
	while (map_vars->map_copy[++i])
	{
		j = -1;
		founded = 0;
		while (map_vars->map_copy[i][++j])
		{
			if (map_vars->map_copy[i][j] == 'P')
			{
				founded = 1;
				map_vars->player.x = j;
				map_vars->player.y = i;
				break ;
			}
		}
		if (founded == 1)
			break ;
	}
}

void	put_on_screen(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					mlx->map->wall.image, j * 32, i * 32);
			if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					mlx->map->collectible.image, j * 32, i * 32);
			if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					mlx->map->player.image, j * 32, i * 32);
			if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					mlx->map->exit.image, j * 32, i * 32);
		}
	}
}

void	free_images(t_mlx *mlx)
{
	if (mlx->map->collectible.image != NULL)
		mlx_destroy_image(mlx->mlx, mlx->map->collectible.image);
	if (mlx->map->exit.image != NULL)
		mlx_destroy_image(mlx->mlx, mlx->map->exit.image);
	if (mlx->map->wall.image != NULL)
		mlx_destroy_image(mlx->mlx, mlx->map->wall.image);
	if (mlx->map->player.image != NULL)
		mlx_destroy_image(mlx->mlx, mlx->map->player.image);
}

void	free_exit(t_mlx *mlx, int state)
{
	if (mlx->map != NULL)
	{
		free_images(mlx);
		if (mlx->map->map)
			free_map(mlx->map->map_copy);
		if (mlx->map->map_copy)
			free_map(mlx->map->map);
		if (mlx->map->file_fd > 3)
			close(mlx->map->file_fd);
	}
	if (mlx->win != NULL && mlx->mlx != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	exit(state);
}
