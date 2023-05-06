/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:59:48 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/06 18:06:25 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ftprintf/ft_printf.h"
# include "libft/libft.h"
# define WIN_WIDTH 500
# define WIN_HEIGHT 500
# define ESC 53
# define UP_ARROW 126
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define RIGHT_ARROW 124

typedef struct player_infos
{
	void	*img;
	int		x;
	int		y;
}	t_player;

typedef struct asset
{
	// char	type;
	int		x;
	int		y;
}	t_asset;

typedef struct mlx_vars
{
	void		*mlx;
	void		*win;
	t_player	player;
}	t_mlx;

typedef struct map_infos
{
	char	**map;
	int		map_width;
	int		map_height;
	t_asset	exit;
	t_asset	player;
	int		is_valid;
	int		collectibles_count;
	int		exit_count;
}	t_map;

int		on_esc_click(int keycode, t_mlx *e);
void	move_player(int keycode, t_player *player, int offset);
int		on_key_click(int keycode, t_mlx *e);
int		on_window_destroy(t_mlx *e);
int		next_frame(t_mlx *e);
t_map	*read_map(char	*file_path);
void	process_map(t_map *map);
#endif