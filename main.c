/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 23:42:23 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/04/26 00:42:57 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "_mlx.h"
#include <stdio.h>

int	on_esc_click(int keycode, t_mlx *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_mlx	mlx;
	void	*img;
	int		img_w;
	int		img_h;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Soooooo long");
	img = mlx_xpm_file_to_image(mlx.mlx, "./xpms/ghost_80x80.xpm", &img_w,
			&img_h);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img, 5, 5);
	// // mlx_clear_window(mlx.mlx, mlx.win);
	// mlx_put_image_to_window(mlx.mlx, mlx.win, img, 50, 5);
	mlx_hook(mlx.win, 2, 0, on_esc_click, &mlx);
	mlx_loop(mlx.mlx);
}
