/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_setting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:58:44 by dongmiki          #+#    #+#             */
/*   Updated: 2023/10/09 16:23:58 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setting_mlx(t_info *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "2D_MAP");

	//mapcpy
	memcpy(game->map, map, sizeof(int) * ROW * COL);

	//map_texture 0:북/ 1:남/ 2:서/ 3:동 -> pasing
	game->map_texture[0].img = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &(game->map_texture[0].width), &(game->map_texture[0].height));
	game->map_texture[1].img = mlx_xpm_file_to_image(game->mlx, "./img/coin.xpm", &(game->map_texture[1].width), &(game->map_texture[1].height));
	game->map_texture[2].img = mlx_xpm_file_to_image(game->mlx, "./img/trash.xpm", &(game->map_texture[2].width), &(game->map_texture[2].height));
	game->map_texture[3].img = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &(game->map_texture[3].width), &(game->map_texture[3].height));
	game->map_texture[0].data = (int *)mlx_get_data_addr(game->map_texture[0].img, &(game->map_texture[0].bpp), &(game->map_texture[0].line_size), &(game->map_texture[0].endian));
	game->map_texture[1].data = (int *)mlx_get_data_addr(game->map_texture[1].img, &(game->map_texture[1].bpp), &(game->map_texture[1].line_size), &(game->map_texture[1].endian));
	game->map_texture[2].data = (int *)mlx_get_data_addr(game->map_texture[2].img, &(game->map_texture[2].bpp), &(game->map_texture[2].line_size), &(game->map_texture[2].endian));
	game->map_texture[3].data = (int *)mlx_get_data_addr(game->map_texture[3].img, &(game->map_texture[3].bpp), &(game->map_texture[3].line_size), &(game->map_texture[3].endian));

	//init vector -> pasing
	game.dir_vec.x = -1;
	game.dir_vec.y = 0;
	//북: 0,1/남 0,-1/ 동1,0/서-1,0

	//init position -> pasing
	game.pos.x = 22;
	game.pos.y = 12;

	//camera 시점인데 y=0.66이 fps게임해서 최적의 시점
	game.camera.x = 0;
	game.camera.y = 0.66;

	//frame  -> 아직 안함 고민중인 부분
	game.frame.time = 0;
	game.frame.old_time = 0;
}