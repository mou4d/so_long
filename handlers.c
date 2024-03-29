/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:23:52 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/10 12:45:44 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_esc_click(int keycode, t_mlx *e)
{
	if (keycode == ESC && e != NULL)
		free_exit(e, 0);
	return (0);
}

int	on_key_click(int keycode, t_mlx *e)
{
	if (keycode != 0 && e != NULL)
	{
		mlx_clear_window(e->mlx, e->win);
		move_player_on_map(e, keycode);
		put_on_screen(e, e->map->map_copy);
	}
	return (0);
}

int	on_window_destroy(t_mlx *e)
{
	free_exit(e, 0);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	if (map != NULL)
	{
		i = -1;
		while (map[++i])
		{
			free(map[i]);
			map[i] = NULL;
		}
		free(map);
		map = NULL;
	}
}
