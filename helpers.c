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

int	*get_player_position(char **map)
{
	int	*values;
	int	i;
	int	j;
	int	founded;

	values = malloc(2 * sizeof(int));
	i = -1;
	while (map[++i])
	{
		j = -1;
		founded = 0;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				founded = 1;
				values[0] = j;
				values[1] = i;
				break ;
			}
		}
		if (founded == 1)
			break ;
	}
	return (values);
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
