/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mlx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:59:48 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/04/26 00:41:27 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MLX_H
# define _MLX_H
# include <unistd.h>
# include <stdlib.h>
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define ESC 53

typedef struct mlx_vars
{
	void	*mlx;
	void	*win;
}	t_mlx;
#endif