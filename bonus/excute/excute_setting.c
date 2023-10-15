/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_setting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:58:44 by dongmiki          #+#    #+#             */
/*   Updated: 2023/10/15 15:23:31 by jeongrol         ###   ########.fr       */
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
	game->camera.x = 0;
	game->camera.y = 0.66;
	game->dir_vec.x = -1;
	game->dir_vec.y = 0;
	rotate(A, game);
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

static char	*setting_mlx_image_string(int num)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (16 + 1));
	i = -1;
	while (++i <= 16)
		str[i] = '\0';
	str = ft_strjoin(str, "./img/door??.xpm", 16);
	if (!str)
		ft_error("MALLOC");
	if (num < 10)
	{
		str[10] = '0';
		str[11] = '0' + num;
	}
	else
	{
		str[10] = '1';
		str[11] = '0' + (num % 10);
	}
	return (str);
}

static void	xpm_image(t_info *game)
{
	game->sprite.img = mlx_xpm_file_to_image(game->mlx, "./img/crosshair.xpm", \
		&(game->sprite.width), &(game->sprite.height));
	if (!game->sprite.img)
		ft_error("IMAGE NOT FOUND");
	game->rider.img = mlx_xpm_file_to_image(game->mlx, "./img/rider.xpm", \
		&(game->rider.width), &(game->rider.height));
	if (!game->rider.img)
		ft_error("IMAGE NOT FOUND");
	game->boom.img = mlx_xpm_file_to_image(game->mlx, "./img/boom.xpm", \
		&(game->boom.width), &(game->boom.height));
	if (!game->boom.img)
		ft_error("IMAGE NOT FOUND");
}

void	setting_mlx(t_info *game, int i)
{
	char	*str;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "2D_MAP");
	i = -1;
	while (++i < 4)
		setting_mlx_map_tex(game, &(game->map_tex[i]), i);
	xpm_image(game);
	i = -1;
	while (++i < 13)
	{
		str = setting_mlx_image_string(i);
		game->door[i].img = mlx_xpm_file_to_image(game->mlx, str, \
		&(game->door[i].width), &(game->door[i].height));
		if (!game->door[i].img)
			ft_error("IMAGE NOT FOUND");
		game->door[i].data = (int *)mlx_get_data_addr(game->door[i].img, \
		&(game->door[i].bpp), &(game->door[i].line_size), \
		&(game->door[i].endian));
		free(str);
	}
	setting_mlx_dir_vec(game);
	mlx_mouse_hide();
	game->mouse = 1;
	game->door_num = 0;
}
