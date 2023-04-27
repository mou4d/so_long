/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mlx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:59:48 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/04/27 19:27:46 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MLX_H
# define _MLX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ftprintf/ft_printf.h"
# include "libft/libft.h"
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
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

typedef struct mlx_vars
{
	void		*mlx;
	void		*win;
	t_player	player;
}	t_mlx;

#endif