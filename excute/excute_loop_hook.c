/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_loop_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:09:30 by dongmiki          #+#    #+#             */
/*   Updated: 2023/10/09 16:52:38 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	screen_setting(t_game *game)
{
	
}

static void	draw_screen(t_game *game)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		screen_setting();
	}
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
}

int	draw_loop(t_info *game)
{
	mlx_clear_window(game->mlx, game->win);
	game->screen.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->screen.width = WIDTH;
	game->screen.height = HEIGHT;
	game->screen.data = (int *)mlx_get_data_addr(game->screen.img, \
	&game->screen.bpp, &game->screen.line_size, &game->screen.endian);
	draw_screen(game);
	mlx_destroy_image(game->mlx ,game->screen.img);
	return (0);
}
