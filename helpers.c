/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:13:03 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/02 17:23:12 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_mlx.h"

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

void	fill_map(char	***map, int x, int y, int map_w, int map_h)
{
	if (x < 0 || x >= map_w
		|| y < 0 || y >= map_h)
		return ;
	if ((*map)[x][y] == '1')
		return ;
	(*map)[x][y] = 'T';
	// fill_map(map, x + 1, y, map_w, map_h);
	// fill_map(map, x - 1, y, map_w, map_h);
	// fill_map(map, x, y + 1, map_w, map_h);
	// fill_map(map, x, y - 1, map_w, map_h);
}

int	*get_player_position(char **map)
{
	int	*values;
	int	i;
	int	j;
	int	founded;

	values = malloc(2 * sizeof(int));
	i = 0;
	while (map[i])
	{
		j = 0;
		founded = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				founded = 1;
				values[0] = j;
				values[1] = i;
				break ;
			}
			j++;
		}
		if (founded == 1)
			break ;
		i++;
	}
	return (values);
}

// int	is_map_path_valid(t_map *map)
// {
// 	char	**map;
	
// 	map = ft_strdup(map->map);
	
// }

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
