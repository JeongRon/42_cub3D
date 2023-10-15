/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:48:18 by dongmiki          #+#    #+#             */
/*   Updated: 2023/10/15 15:39:10 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	color_map(t_info *game, int *xy, int px, int py)
{
	int	i;
	int	j;
	int	color;

	j = -1;
	if (xy[1] == (int)game->pos.x && xy[0] == (int)game->pos.y)
		color = 0xFF0000;
	else if (game->map[xy[1]][xy[0]] == '0')
		color = 0xFFFFFF;
	else if (game->map[xy[1]][xy[0]] == '1')
		color = 0x000000;
	else if (game->map[xy[1]][xy[0]] == 'D' || game->map[xy[1]][xy[0]] == '#')
		color = 0x8B4513;
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
	int	tmp_xy[2];

	y = -1;
	while (++y < 7)
	{
		x = -1;
		tmp_xy[1] = (int)(game->pos.x - 3 + y);
		while (++x < 11)
		{
			tmp_xy[0] = (int)(game->pos.y - 5 + x);
			if (tmp_xy[0] >= 0 && tmp_xy[1] >= 0 \
			&& tmp_xy[0] < game->col && tmp_xy[1] < game->row)
				color_map(game, tmp_xy, x, y);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->mini.img, 0, 0);
}
