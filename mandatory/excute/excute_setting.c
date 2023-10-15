/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_setting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:58:44 by dongmiki          #+#    #+#             */
/*   Updated: 2023/10/15 15:19:57 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	setting_mlx_map_tex(t_info *game, t_img *map_tex, int dir)
{
	if (dir == 0)
	{
		map_tex->img = mlx_xpm_file_to_image(game->mlx, game->no, \
		&(map_tex->width), &(map_tex->height));
	}
	else if (dir == 1)
	{
		map_tex->img = mlx_xpm_file_to_image(game->mlx, game->so, \
		&(map_tex->width), &(map_tex->height));
	}
	else if (dir == 2)
	{
		map_tex->img = mlx_xpm_file_to_image(game->mlx, game->we, \
		&(map_tex->width), &(map_tex->height));
	}
	else if (dir == 3)
	{
		map_tex->img = mlx_xpm_file_to_image(game->mlx, game->ea, \
		&(map_tex->width), &(map_tex->height));
	}
	if (!map_tex->img)
		ft_error("IMAGE NOT FOUND");
	map_tex->data = (int *)mlx_get_data_addr(map_tex->img, &(map_tex->bpp), \
	&(map_tex->line_size), &(map_tex->endian));
}

static void	setting_mlx_dir_vec(t_info *game)
{
	int	temp;

	temp = -1;
	game->dir_vec.x = -1;
	game->dir_vec.y = 0;
	if (game->pos_dir == 'N')
		return ;
	else if (game->pos_dir == 'S')
		while (++temp < 36)
			rotate(D, game);
	else if (game->pos_dir == 'W')
		while (++temp < 18)
			rotate(A, game);
	else if (game->pos_dir == 'E')
		while (++temp < 18)
			rotate(D, game);
}

void	setting_mlx(t_info *game, int k)
{
	int	i;

	(void)k;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "2D_MAP");
	i = -1;
	while (++i < 4)
		setting_mlx_map_tex(game, &(game->map_tex[i]), i);
	game->camera.x = 0;
	game->camera.y = 0.66;
	setting_mlx_dir_vec(game);
}
