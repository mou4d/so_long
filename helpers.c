/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:13:03 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/08 20:31:48 by mbousbaa         ###   ########.fr       */
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

void	move_player_on_map(t_map *map_vars, int key)
{
	int	x;
	int	y;

	x = get_player_position(map_vars->map_copy)[0];
	y = get_player_position(map_vars->map_copy)[1];
	if (key == UP_ARROW)
	{
		y--;
		if (map_vars->map_copy[y][x] != '1')
		{
			if (map_vars->map_copy[y][x] == 'C')
				map_vars->collectibles_count--;
			map_vars->map_copy[y + 1][x] = '0';
			map_vars->map_copy[y][x] = 'P';
		}
	}
	if (key == DOWN_ARROW)
	{
		y++;
		if (map_vars->map_copy[y][x] != '1')
		{
			if (map_vars->map_copy[y][x] == 'C')
				map_vars->collectibles_count--;
			map_vars->map_copy[y - 1][x] = '0';
			map_vars->map_copy[y][x] = 'P';
		}
	}
	if (key == RIGHT_ARROW)
	{
		x++;
		if (map_vars->map_copy[y][x] != '1')
		{
			if (map_vars->map_copy[y][x] == 'C')
				map_vars->collectibles_count--;
			map_vars->map_copy[y][x - 1] = '0';
			map_vars->map_copy[y][x] = 'P';
		}
	}
	if (key == LEFT_ARROW)
	{
		x--;
		if (map_vars->map_copy[y][x] != '1')
		{
			if (map_vars->map_copy[y][x] == 'C')
				map_vars->collectibles_count--;
			map_vars->map_copy[y][x + 1] = '0';
			map_vars->map_copy[y][x] = 'P';
		}
	}
	map_vars->player.x = x;
	map_vars->player.y = y;
	// ft_printf("p_x=%d, p_y=%d\n", x, y);
	// int i = -1;
	// while (map_vars->map_copy[++i])
	// {
	// 	ft_printf("%s\n", map_vars->map_copy[i]);
	// }
}

void	move_player(int keycode, t_player *player)
{
	int	curr_pos_x;
	int	curr_pos_y;

	curr_pos_x = player->x;
	curr_pos_y = player->y;
	if (keycode == UP_ARROW && curr_pos_y > 32)
		player->y -= 32;
	else if (keycode == DOWN_ARROW && curr_pos_y < WIN_HEIGHT)
		player->y += 32;
	else if (keycode == LEFT_ARROW && curr_pos_x > 32)
		player->x -= 32;
	else if (keycode == RIGHT_ARROW && curr_pos_x < WIN_WIDTH)
		player->x += 32;
	// ft_printf("x %d\ty %d\n", player->x, player->y);
}

void	put_on_screen(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = -1;
	ft_printf("MAP GOOD?\n");
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
			if (map[i][j] == 'E' && mlx->map->collectibles_count == 0)
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					mlx->map->exit.image, j * 32, i * 32);
			ft_printf("\nlast collectibles = %d\n", mlx->map->collectibles_count);
		}
	}	
}