/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_loop_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:09:30 by dongmiki          #+#    #+#             */
/*   Updated: 2023/10/13 16:37:10 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	where_tex_x(t_screen *s, t_info *game)
{
	int		tex_x;
	double	hit_wall_x;

	if (s->side == 0)
		hit_wall_x = game->pos.y + (s->ray_distance * s->ray.y);
	else
		hit_wall_x = game->pos.x + (s->ray_distance * s->ray.x);
	hit_wall_x -= floor((hit_wall_x));

	tex_x = (int)(hit_wall_x * (double)game->map_tex[s->what_hit].height);
	s->tex_x = tex_x;
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

void	draw_door(t_info *game, int x, t_screen *s, int door_num)
{
	int		y;
	int		tex_y;
	double	step_y;
	double	tex_pos;

	y = -1;
	while (++y < s->draw[0])
		game->screen.data[game->screen.width * y + x] = 0x00FF00;
	step_y = 1.0 * game->door[door_num].height / s->line_height;
	tex_pos = (s->draw[0] - HEIGHT / 2 + s->line_height / 2) * step_y;
	y--;
	while (++y < s->draw[1])
	{
		tex_y = (int)tex_pos & (game->door[door_num].height - 1);
		tex_pos += step_y;
		game->screen.data[game->screen.width * y + x] = \
			game->door[door_num].data[game->door[door_num].height \
			* tex_y + s->tex_x];
	}
	y--;
	while (++y < HEIGHT)
		game->screen.data[game->screen.width * y + x] = 0x0000FF;
}

static void	draw_sprite(t_info *game, int x, int y)
{
	if (game->mouse == 0)
	{	
		game->ani_time = 0;
		return ;
	}
	x = WIDTH - (game->ani_time);
	y = (game->ani_time / 2);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite.img, \
	WIDTH / 2 - 112, HEIGHT / 2 - 113);
	if (game->ani_time > 0 && game->ani_time < HEIGHT - 192)
	{
		game->ani_time += 10;
		mlx_put_image_to_window(game->mlx, game->win, game->rider.img, x, y);
	}
	if (game->ani_time > HEIGHT - 192)
	{
		game->ani_time += 10;
		mlx_put_image_to_window(game->mlx, game->win, game->boom.img, \
		(WIDTH / 2) - (game->boom.width / 2), \
		(HEIGHT / 2) - (game->boom.height / 2));
	}
	if (game->ani_time > HEIGHT + 100)
		game->ani_time = 0;
}

int	draw_loop(t_info *game)
{
	game->ani = (game->ani + 1) % 300;
	mouse_event(game);
	mlx_clear_window(game->mlx, game->win);
	game->screen.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->screen.width = WIDTH;
	game->screen.height = HEIGHT;
	game->screen.data = (int *)mlx_get_data_addr(game->screen.img, \
	&game->screen.bpp, &game->screen.line_size, &game->screen.endian);
	draw_screen(game, game->ani);
	mlx_destroy_image(game->mlx, game->screen.img);
	game->mini.img = mlx_new_image(game->mlx, MINWIDTH, MINHEIGHT);
	game->mini.img = mlx_new_image(game->mlx, MINWIDTH, MINHEIGHT);
	game->mini.width = MINWIDTH;
	game->mini.height = MINHEIGHT;
	game->mini.data = (int *)mlx_get_data_addr(game->mini.img, \
	&game->mini.bpp, &game->mini.line_size, &game->mini.endian);
	draw_minimap(game);
	mlx_destroy_image(game->mlx, game->mini.img);
	draw_sprite(game, 0, 0);
	if (find_door(game) > 0)
		mlx_string_put(game->mlx, game->win, (WIDTH / 2) - 50, \
		HEIGHT / 3, 0xFFFFFF, "Push the 'K'.");
	rotate_door(game);
	return (0);
}
