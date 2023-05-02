/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:13:03 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/02 00:36:25 by mbousbaa         ###   ########.fr       */
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

int	is_map_path_valid(char	**map)
{
	int	is_valid;
	int	i;
	int	j;
	int	borders[2];

	i = 0;
	j = 0;
	is_valid = 1;
	while (map[i])
	{
		while (map[i][j])
			j++;
		i++;
	}
	borders[0] = j;
	borders[1] = i;
	ft_printf("\n map_x : %d\tmap_y: %d\n", borders[0], borders[1]);
	i = 0;
	j = 0;
	while (map[i])
	{
		ft_printf("\nLine %d processed\n", i+1);
		j = 0;
		while (map[i][j] != '\0' && i <= 6)
		{
			if (map[i][j] == 'P')
			{
				if ((i - 1) > 0)
				{
					if (map [i - 1][j] != '1')
						map[i - 1][j] = 'P';
				}
				if ((j + 1) < borders[0])
				{
					if (map[i][j + 1] != '1')
						map[i][j + 1] = 'P';
				}
				if ((j - 1) > 0)
				{
					if (map[i][j - 1] != '1')
						map[i][j - 1] = 'P';
				}
				if ((i + 1) < borders[1])
				{
					if (map[i + 1][j] != '1')
						map[i + 1][j] = 'P';
				}
			}
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (map[i])
	{
		ft_printf(map[i]);
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				is_valid = 0;
				break ;
			}
			j++;
		}
		i++;
		ft_printf("\n");
	}
	ft_printf("is valid = %d\n", is_valid);
	return (is_valid);
}

int	map_check(char *file_path)
{
	int		i;
	int		map_file;
	char	*buffer;
	char	**map;
	int		*elemets_check_result;

	map = NULL;
	i = 0;
	buffer = malloc(1024 * sizeof(char));
	map_file = open(file_path, O_RDONLY);
	i = read(map_file, buffer, 1024);
	buffer[i] = '\0';
	ft_printf("%s\n", buffer);
	if (i > 0)
	{
		map = ft_split(buffer, '\n');
	}
	elemets_check_result = get_map_elements_count(buffer);
	ft_printf("\nelements count :\n\tcollectibles : %d\n\tplayer : %d\n\texit : %d\n", elemets_check_result[0], elemets_check_result[1], elemets_check_result[2]);	
	// while (*map != NULL)
	// {
	// 	ft_printf("\n%s\n", *map);
	// 	map++;
	// }
	is_map_path_valid(map);
	return (i);
}
