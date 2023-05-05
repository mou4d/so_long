/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:39:55 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/05 20:28:23 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*get_map_elements_count(char *map)
{
	int		*elements_count;
	int		i;

	i = 0;
	elements_count = malloc(3 * sizeof(int));
	if (!elements_count)
		return (NULL);
	while (i < 3)
		elements_count[i++] = 0;
	while (*map)
	{
		if (*map == 'C')
			elements_count[0]++;
		else if (*map == 'E')
			elements_count[1]++;
		else if (*map == 'P')
			elements_count[2]++;
		map++;
	}
	return (elements_count);
}

void	check_path(t_map *map, int x, int y)
{
	ft_printf("\n[DEBUG] x=%d, y=%d\n", x, y);
	ft_printf("\n[DEBUG] map_w=%d, map_h=%d\n", map->map_width, map->map_height);
	if (map->map[y] == NULL || map->map[y][x] == '\0')
		return ;
	if (x < 0 || x >= map->map_width
		|| y < 0 || y >= map->map_height)
		return ;
	ft_printf("\n[DEBUG] aimed map element : %c\n", map->map[y][x]);
	if (map->map[y][x] == '1')
		return ;
	map->map[y][x] = '1';
	check_path(map, x + 1, y);
	check_path(map, x - 1, y);
	check_path(map, x, y + 1);
	check_path(map, x, y - 1);
}

t_map	*process_map(t_map *map)
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
				map->player.type = 'P';
				map->player.x = j;
				map->player.y = i;
			}
			else if (map->map[i][j] == 'E')
			{
				map->exit.type = 'E';
				map->exit.x = j;
				map->exit.y = i;
			}
		}
	}
	map->map_width = j;
	map->map_height = i;
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
				return (map);
			}
		}
	}
	map->is_valid = 1;
	return (map);
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