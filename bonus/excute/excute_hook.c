/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:09:03 by dongmiki          #+#    #+#             */
/*   Updated: 2023/10/15 15:23:01 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	rotate(int keycode, t_info *g)
{
	double	r_s;
	double	temp;

	r_s = PI / 36;
	if (keycode == D)
	{
		temp = g->dir_vec.x;
		g->dir_vec.x = g->dir_vec.x * cos(-r_s) - g->dir_vec.y * sin(-r_s);
		g->dir_vec.y = temp * sin(-r_s) + g->dir_vec.y * cos(-r_s);
		temp = g->camera.x;
		g->camera.x = g->camera.x * cos(-r_s) - g->camera.y * sin(-r_s);
		g->camera.y = temp * sin(-r_s) + g->camera.y * cos(-r_s);
	}
	if (keycode == A)
	{
		temp = g->dir_vec.x;
		g->dir_vec.x = g->dir_vec.x * cos(r_s) - g->dir_vec.y * sin(r_s);
		g->dir_vec.y = temp * sin(r_s) + g->dir_vec.y * cos(r_s);
		temp = g->camera.x;
		g->camera.x = g->camera.x * cos(r_s) - g->camera.y * sin(r_s);
		g->camera.y = temp * sin(r_s) + g->camera.y * cos(r_s);
	}
}

static void	move(int keycode, t_info *g)
{
	double	m_s;

	m_s = 1;
	if (keycode == W)
	{
		if (g->map[(int)(g->pos.x + g->dir_vec.x * m_s)][(int)(g->pos.y)] \
		<= '0')
			g->pos.x += g->dir_vec.x * (m_s / 2);
		if (g->map[(int)(g->pos.x)][(int)(g->pos.y + g->dir_vec.y * m_s)] \
		<= '0')
			g->pos.y += g->dir_vec.y * (m_s / 2);
	}
	if (keycode == S)
	{
		if (g->map[(int)(g->pos.x - g->dir_vec.x * m_s)][(int)(g->pos.y)] \
		<= '0')
			g->pos.x -= g->dir_vec.x * (m_s / 2);
		if (g->map[(int)(g->pos.x)][(int)(g->pos.y - g->dir_vec.y * m_s)] \
		<= '0')
			g->pos.y -= g->dir_vec.y * (m_s / 2);
	}
}

static void	mouse_vision(t_info *game)
{
	if (game->mouse == 1)
	{
		mlx_mouse_show();
		game->mouse = 0;
	}
	else
	{
		mlx_mouse_hide();
		game->mouse = 1;
	}
}

int	key_press(int keycode, t_info *g)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == W)
		move(keycode, g);
	if (keycode == S)
		move(keycode, g);
	if (keycode == D)
		rotate(keycode, g);
	if (keycode == A)
		rotate(keycode, g);
	if (keycode == ONE)
		mouse_vision(g);
	if (keycode == K)
		door_control(g);
	return (0);
}

int	exit_button(void)
{
	exit(0);
}
