/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:48:18 by dongmiki          #+#    #+#             */
/*   Updated: 2023/10/13 14:16:56 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
//330 * 210 -> 30 * 30
//11*7
// me: red/ wall:brwoun /back:whilte

static int	color_map(t_info *game, int x, int y, int px, int py)
{
	int	i;
	int	j;
	int	color;

	j = -1;
	if (y == (int)game->pos.x && x == (int)game->pos.y)
		color = 0xFF0000;
	else if (game->map[y][x] == '0')
		color = 0xFFFFFF;
	else if (game->map[y][x] == '1')
		color = 0x000000;
	else
		color = 0x000000;
	while (++j < MINTILE)
	{
		i = -1;
		while (++i < MINTILE)
			game->mini.data[MINWIDTH * (MINTILE * py + j) \
			+ (MINTILE * px + i)] = color;
	}
	return (color);
}

void	draw_minimap(t_info *game)
{
	int	x;
	int	y;
	int	tmp_x;
	int	tmp_y;

	y = -1;
	while (++y < 7)
	{
		x = -1;
		tmp_y = (int)(game->pos.x - 3 + y);
		while (++x < 11)
		{
			tmp_x = (int)(game->pos.y - 5 + x);
			if (tmp_x >= 0 && tmp_y >= 0 \
			&& tmp_x < game->col && tmp_y < game->row)
				color_map(game, tmp_x, tmp_y, x, y);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->mini.img, 0, 0);
}
