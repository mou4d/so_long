/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:13:03 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/04 16:41:57 by mbousbaa         ###   ########.fr       */
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
