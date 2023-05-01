/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:13:03 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/01 00:25:17 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_mlx.h"

int	map_check(char *file_path)
{
	int		i;
	int		map_file;
	char	*buffer;
	char	**map=NULL;

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
	while (*map)
	{
		ft_printf("\n%s\n", *map);
		map++;
	}
	return (i);
}

int	check_collectibles(const char **map)
{
	int	i;

	i = 0;
	while (*map)
	{
		while (*(*map))
		{
			if (*(*map) == 'C')
				i++;
			(*map)++;
		}
		map++;
	}
	return (i);
}