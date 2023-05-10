/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:38:38 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/10 17:50:23 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (get_map_elements_count(map) == 0)
		ft_printf("Error, need more elements in the map\n");
	check_path(map, map->player.x, map->player.y);
	i = -1;
	while (map->map[++i])
	{
		if (ft_strchr(map->map[i], '1') == NULL)
		{
			map->is_valid = 0;
			break ;
		}
	}
	map->is_valid = 1;
}

int	validate_map(t_map *map_vars)
{
	int	ret;

	ret = 1;
	if (map_vars != NULL)
	{
		ret = check_lines_len(map_vars);
		ret = check_map_elemets(map_vars->map, map_vars->map_width,
				map_vars->map_height);
		ret = get_map_elements_count(map_vars);
		if (ret == 0)
		{
			free(map_vars->map);
			free(map_vars->map_copy);
			free(map_vars);
			map_vars = NULL;
		}
	}
	return (ret);
}

int	split_map(t_map *map_vars, char *buffer)
{
	int	ret;

	ret = 1;
	ret = check_map_new_lines(buffer);
	if (ret == 1)
	{
		map_vars->map = ft_split(buffer, '\n');
		map_vars->map_copy = ft_split(buffer, '\n');
	}
	else
	{
		free(map_vars);
		map_vars = NULL;
	}
	return (ret);
}

/// @brief read the map file
/// @param file_path path to the map file
/// @return pointer to a t_map struct
t_map	*read_map(char	*file_path)
{
	char	buffer[1024];
	int		i;
	int		is_valid;
	t_map	*ret;

	ret = NULL;
	is_valid = 1;
	if (ft_strncmp(ft_strchr(file_path, '.'), ".ber", 4) == 0)
	{
		ret = malloc(sizeof(t_map));
		if (!ret)
			return (NULL);
		ret->file_fd = open(file_path, O_RDONLY);
		i = read(ret->file_fd, buffer, 1024);
		if (i <= 0)
		{
			free(ret);
			return (NULL);
		}
		buffer[i] = '\0';
		is_valid = split_map(ret, buffer);
		if (is_valid == 0)
			return (NULL);
	}
	return (ret);
}
