/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:59:48 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/05/09 12:45:58 by mbousbaa         ###   ########.fr       */
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
	void	*image;
	int		x;
	int		y;
}	t_asset;

typedef struct map_infos
{
	char	**map;
	char	**map_copy;
	int		file_fd;
	int		map_width;
	int		map_height;
	t_asset	player;
	t_asset	collectible;
	t_asset	floor;
	t_asset	wall;
	t_asset	exit;
	int		collectibles_count;
	int		exit_count;
	int		player_count;
	int		is_valid;
}	t_map;

typedef struct mlx_vars
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		*map;
}	t_mlx;

int		on_esc_click(int keycode, t_mlx *e);
int		on_key_click(int keycode, t_mlx *e);
int		on_window_destroy(t_mlx *e);
int		next_frame(t_mlx *e);

int		check_lines_len(t_map *map_vars);
int		check_map_elemets(char **map, int map_width, int map_height);
int		check_map_new_lines(char *map);
int		get_map_elements_count(t_map *map_vars);
void	check_path(t_map *map, int x, int y);
void	process_map(t_map *map);
int		validate_map(t_map *map_vars);
t_map	*read_map(char	*file_path);

void	put_on_screen(t_mlx *mlx, char **map);
void	move_player(int keycode, t_player *player);
void	move_player_on_map(t_map *map_vars, int key);
#endif