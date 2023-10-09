/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_loop_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:09:30 by dongmiki          #+#    #+#             */
/*   Updated: 2023/10/09 20:19:13 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	where_tex_x(t_screen *s, t_info *game)
{
	int		tex_x;
	double	hit_wall_x;

	if (s->side == 0)
		hit_wall_x = game->pos.y + (s->ray_distance * s->ray.y);
	else
		hit_wall_x = game->pos.x + (s->ray_distance * s->ray.x);
	hit_wall_x -= floor((hit_wall_x));

	tex_x = (int)(hit_wall_x * (double)TILE_SIZE);
	s->tex = tex_x;
}

void	where_hit_wall(t_screen *s, t_info *game)
{
	if (s->side == 0)
	{
		if ((s->map[0] - game->pos.x) > 0)
			s->what_hit = 0;
		else
			s->what_hit = 1;
	}
	else
	{
		if ((s->map[1] - game->pos.y) > 0)
			s->what_hit = 2;
		else
			s->what_hit = 3;
	}
}

int	draw_loop(t_info *game)
{
		printf("3\n");
	mlx_clear_window(game->mlx, game->win);
	game->screen.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->screen.width = WIDTH;
	game->screen.height = HEIGHT;
	game->screen.data = (int *)mlx_get_data_addr(game->screen.img, \
	&game->screen.bpp, &game->screen.line_size, &game->screen.endian);
			printf("4\n");
	draw_screen(game);
	mlx_destroy_image(game->mlx, game->screen.img);
	return (0);
}
