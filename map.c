/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:39:55 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/07 01:53:10 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_lines_len(t_map *map_vars)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map_vars->map[i]);
	while (map_vars->map[i])
	{
		if ((int) ft_strlen(map_vars->map[i]) != len)
			return (0);
		i++;
	}
	map_vars->map_height = i;
	map_vars->map_width = len;
	return (1);
}

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
	// i = -1;
	// while (map[++i])
	// {
	// 	j = -1;
	// 	while (map[i][++j])
	// 	{
	// 		if (map[i][j] != '1' || map[i][j] != '0' || map[i][j] != 'P'
	// 			|| map[i][j] != 'C' || map[i][j] != 'E')
	// 			return (0);
	// 	}
	// }
	return (1);
}

int	get_map_elements_count(t_map *map_vars)
{
	int	i;
	int	j;

	i = -1;
	map_vars->collectibles_count = 0;
	map_vars->exit_count = 0;
	while (map_vars->map[++i])
	{
		j = -1;
		while (map_vars->map[i][++j])
		{
			if (map_vars->map[i][j] == 'C')
				map_vars->collectibles_count++;
			if (map_vars->map[i][j] == 'E')
				map_vars->exit_count++;
		}
	}
	ft_printf("\n[DEBUG]\n\tcollectibles : %d \n\texit : %d\n", map_vars->collectibles_count, map_vars->exit_count);
	if (map_vars->exit_count != 1 || map_vars->collectibles_count < 1)
		return (0);
	return (1);
}

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

void	process_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
			{
				map->player.x = j;
				map->player.y = i;
			}
		}
	}
	if (check_lines_len(map) == 0)
		ft_printf("Error, map need to be aligned\n");
	ft_printf("[DEBUG] map_width : %d | map_height : %d\n", map->map_width, map->map_height);
	if (check_map_elemets(map->map, map->map_width, map->map_height) == 0)
		ft_printf("Error, map not closed\n");
	if (get_map_elements_count(map) == 0)
		ft_printf("Error, need more elements in the map\n");
	check_path(map, map->player.x, map->player.y);
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] != '1')
			{	
				map->is_valid = 0;
				return ;
			}
		}
	}
	map->is_valid = 1;
}

t_map	*read_map(char	*file_path)
{
	int		map_fd;
	char	buffer[1024];
	int		i;
	t_map	*ret;

	map_fd = open(file_path, O_RDONLY);
	i = read(map_fd, buffer, 1024);
	buffer[i] = '\0';
	ret = malloc(sizeof(t_map));
	ret->map = ft_split(buffer, '\n');
	return (ret);
}
