/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:39:55 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/06 17:19:30 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_lines_len(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if ((int) ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
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
			else if (map->map[i][j] == 'E')
			{
				map->exit.x = j;
				map->exit.y = i;
			}
		}
	}
	map->map_width = j;
	map->map_height = i;
	if (get_map_elements_count(map) == 0)
		ft_printf("Error, need more elements in the map");
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
