/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:39:55 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/10 16:35:40 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief check if all lines in the map are correctly alligned
/// @param map_vars pointer to the map struct
/// @return 
int	check_lines_len(t_map *map_vars)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map_vars->map[i]);
	if (len > 80)
		return (0);
	while (map_vars->map[i])
	{
		if ((int) ft_strlen(map_vars->map[i]) != len)
			return (0);
		i++;
	}
	if (i > 43)
		return (0); 
	map_vars->map_height = i;
	map_vars->map_width = len;
	return (1);
}

/// @brief check if all elements are present in the map 
/// and if the map borders are correctly closed
/// @param map 2d array representation of the map
/// @param map_width width of the map
/// @param map_height height of the map
/// @return 1 if the map is valid, 0 if not
int	check_map_elemets(char **map, int map_width, int map_height)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_height && map[i])
	{
		if (map[i][0] != '1' || map[i][map_width - 1] != '1')
			return (0);
	}
	j = -1;
	while (++j < map_width && map[0][j] && map[map_height - 1][j])
		if (map[0][j] != '1' || map[map_height - 1][j] != '1')
			return (0);
	i = 0;
	while (++i < map_height - 1 && map[i])
	{
		j = 0;
		while (++j < map_width - 1 && map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E')
				return (0);
		}
	}
	return (1);
}

/// @brief count the elements of the map (collectibles, exit, player ...)
/// @param map_vars pointer to the map struct
/// @return 0 if any element of the map is missing,
/// 1 if there is at least 1 collectible and an exit and a player
int	get_map_elements_count(t_map *map_vars)
{
	int	i;
	int	j;

	map_vars->collectibles_count = 0;
	map_vars->exit_count = 0;
	map_vars->player_count = 0;
	i = -1;
	while (map_vars->map[++i])
	{
		j = -1;
		while (map_vars->map[i][++j])
		{
			if (map_vars->map[i][j] == 'C')
				map_vars->collectibles_count++;
			if (map_vars->map[i][j] == 'E')
				map_vars->exit_count++;
			if (map_vars->map[i][j] == 'P')
				map_vars->player_count++;
		}
	}
	if (map_vars->exit_count != 1 || map_vars->collectibles_count < 1
		|| map_vars->player_count != 1)
		return (0);
	return (1);
}

/// @brief fill all the valid path that the player can go through with 1,
/// means the player can collect all collectibles and reach the exit 
/// @param map pointer to the map struct 
/// @param x player x position
/// @param y player y position
void	check_path(t_map *map, int x, int y)
{
	if (map->map[y] == NULL || map->map[y][x] == '\0')
		return ;
	if (x < 0 || x >= map->map_width
		|| y < 0 || y >= map->map_height)
		return ;
	if (map->map[y][x] == '1')
		return ;
	map->map[y][x] = '1';
	check_path(map, x + 1, y);
	check_path(map, x - 1, y);
	check_path(map, x, y + 1);
	check_path(map, x, y - 1);
}

int	check_map_new_lines(char *map)
{
	int	i;

	if (map[0] == '\n')
		return (0);
	i = -1;
	while (map[++i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (0);
	}
	if (map[i - 1] == '\n')
		return (0);
	return (1);
}
