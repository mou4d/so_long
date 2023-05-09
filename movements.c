/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:11:50 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/09 15:50:11 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map_vars, int *x, int *y, char *prev_element)
{
	(*y)--;
	if (map_vars->map_copy[*y][*x] != '1' && *y > 0)
	{
		*prev_element = map_vars->map_copy[*y][*x];
		ft_printf("[DEBUG] prev_element = %c\n", *prev_element);
		if (map_vars->map_copy[*y][*x] == 'C')
			map_vars->collectibles_count--;
		map_vars->map_copy[*y + 1][*x] = '0';
		map_vars->map_copy[*y][*x] = 'P';
	}
}

void	move_down(t_map *map_vars, int *x, int *y, char *prev_element)
{
	(*y)++;
	if (map_vars->map_copy[*y][*x] != '1' && *y < map_vars->map_height - 1)
	{
		*prev_element = map_vars->map_copy[*y][*x];
		ft_printf("[DEBUG] prev_element = %c\n", *prev_element);
		if (map_vars->map_copy[*y][*x] == 'C')
			map_vars->collectibles_count--;
		map_vars->map_copy[*y - 1][*x] = '0';
		map_vars->map_copy[*y][*x] = 'P';
	}
}

void	move_right(t_map *map_vars, int *x, int *y, char *prev_element)
{
	(*x)++;
	if (map_vars->map_copy[*y][*x] != '1' && *x < map_vars->map_width - 1)
	{
		*prev_element = map_vars->map_copy[*y][*x];
		ft_printf("[DEBUG] prev_element = %c\n", *prev_element);
		if (map_vars->map_copy[*y][*x] == 'C')
			map_vars->collectibles_count--;
		map_vars->map_copy[*y][*x - 1] = '0';
		map_vars->map_copy[*y][*x] = 'P';
	}
}

void	move_left(t_map *map_vars, int *x, int *y, char *prev_element)
{
	(*x)--;
	if (map_vars->map_copy[*y][*x] != '1' && *x > 0)
	{
		*prev_element = map_vars->map_copy[*y][*x];
		ft_printf("[DEBUG] prev_element = %c\n", *prev_element);
		if (map_vars->map_copy[*y][*x] == 'C')
			map_vars->collectibles_count--;
		map_vars->map_copy[*y][*x + 1] = '0';
		map_vars->map_copy[*y][*x] = 'P';
	}
}

void	move_player_on_map(t_map *map_vars, int key)
{
	int			x;
	int			y;
	int			exit_hitted;
	static char	prev_element;

	exit_hitted = 0;
	x = get_player_position(map_vars->map_copy)[0];
	y = get_player_position(map_vars->map_copy)[1];
	if (key == UP_ARROW)
		move_up(map_vars, &x, &y, &prev_element);
	else if (key == DOWN_ARROW)
		move_down(map_vars, &x, &y, &prev_element);
	else if (key == RIGHT_ARROW)
		move_right(map_vars, &x, &y, &prev_element);
	else if (key == LEFT_ARROW)
		move_left(map_vars, &x, &y, &prev_element);
	map_vars->player.x = x;
	map_vars->player.y = y;
	// ft_printf("p_x=%d, p_y=%d\n", x, y);
	// int i = -1;
	// while (map_vars->map_copy[++i])
	// {
	// 	ft_printf("%s\n", map_vars->map_copy[i]);
	// }
}