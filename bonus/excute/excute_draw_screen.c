/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_draw_screen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:42:35 by dongmiki          #+#    #+#             */
/*   Updated: 2023/10/13 14:54:17 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	line_texture(t_info *game, int x, t_screen *s, int time)
{
	int		y;
	int		tex_y;
	double	step_y;
	double	tex_pos;

	y = -1;
	while (++y < s->draw[0])
		game->screen.data[game->screen.width * y + x] = 0x00FF00;
	step_y = 1.0 * game->map_tex[s->what_hit].height / s->line_height;
	tex_pos = (s->draw[0] - HEIGHT / 2 + s->line_height / 2) * step_y;
	y--;
	s->tex_x = (s->tex_x + time) % game->map_tex[s->what_hit].width;
	while (++y < s->draw[1])
	{
		tex_y = (int)tex_pos & (game->map_tex[s->what_hit].height - 1);
		tex_pos += step_y;
		game->screen.data[game->screen.width * y + x] = \
			game->map_tex[s->what_hit].data[game->map_tex[s->what_hit].height \
			* tex_y + s->tex_x];
	}
	y--;
	while (++y < HEIGHT)
		game->screen.data[game->screen.width * y + x] = 0x0000FF;
}

static void	calculation_draw_size(t_screen *s)
{
	int		line_height;
	int		draw_start;
	int		draw_end;

	line_height = (int)(HEIGHT / s->ray_distance);
	draw_start = (-line_height / 2) + (HEIGHT / 2);
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (line_height / 2) + (HEIGHT / 2);
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	s->draw[0] = draw_start;
	s->draw[1] = draw_end;
	s->line_height = line_height;
}

//Digital Differential Analyzer
static void	dda_and_vertical_distance(t_screen *s, t_info *game, int hit)
{
	while (hit == 0)
	{
		if (s->side_dis.x < s->side_dis.y)
		{
			s->side_dis.x += s->delta_dis.x;
			s->map[0] += s->step[0];
			s->side = 0;
		}
		else
		{
			s->side_dis.y += s->delta_dis.y;
			s->map[1] += s->step[1];
			s->side = 1;
		}
		if (game->map[s->map[0]][s->map[1]] > '0')
			hit = 1;
	}
	if (s->side == 0)
		s->ray_distance = (s->map[0] - game->pos.x + \
		(1 - s->step[0]) / 2) / s->ray.x;
	else
		s->ray_distance = (s->map[1] - game->pos.y + \
		(1 - s->step[1]) / 2) / s->ray.y;
}

static void	screen_setting(t_screen *s, t_info *game, int x)
{
	double	screen_x;

	screen_x = 2 * x / ((double)WIDTH) - 1;
	s->ray.x = game->dir_vec.x + (game->camera.x * screen_x);
	s->ray.y = game->dir_vec.y + (game->camera.y * screen_x);
	s->map[0] = (int)game->pos.x;
	s->map[1] = (int)game->pos.y;
	s->delta_dis.x = ft_abs(1 / s->ray.x);
	s->delta_dis.y = ft_abs(1 / s->ray.y);
	s->step[0] = 1;
	s->step[1] = 1;
	if (s->ray.x < 0)
	{
		s->step[0] = -1;
		s->side_dis.x = (game->pos.x - s->map[0]) * s->delta_dis.x;
	}
	else
		s->side_dis.x = (s->map[0] + 1.0 - game->pos.x) * s->delta_dis.x;
	if (s->ray.y < 0)
	{
		s->step[1] = -1;
		s->side_dis.y = (game->pos.y - s->map[1]) * s->delta_dis.y;
	}
	else
		s->side_dis.y = (s->map[1] + 1.0 - game->pos.y) * s->delta_dis.y;
}

void	draw_screen(t_info *game, int time)
{
	int			x;
	t_screen	screen;

	x = -1;
	while (++x < WIDTH)
	{
		screen_setting(&screen, game, x);
		dda_and_vertical_distance(&screen, game, 0);
		calculation_draw_size(&screen);
		where_hit_wall(&screen, game);
		where_tex_x(&screen, game);
		// if (game->map[screen->map[0]][screen->map[1]] == 'D')
		// 	line_texture2
		line_texture(game, x, &screen, time);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
}
