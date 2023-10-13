/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:09:03 by dongmiki          #+#    #+#             */
/*   Updated: 2023/10/13 14:40:44 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

//r_s is temp value | maybe change info->frame rotate_speed
void	rotate(int keycode, t_info *g)
{
	double	r_s;
	double	temp;

	r_s = PI / 36;
	if (keycode == A)
	{
		temp = g->dir_vec.x;
		g->dir_vec.x = g->dir_vec.x * cos(-r_s) - g->dir_vec.y * sin(-r_s);
		g->dir_vec.y = temp * sin(-r_s) + g->dir_vec.y * cos(-r_s);
		temp = g->camera.x;
		g->camera.x = g->camera.x * cos(-r_s) - g->camera.y * sin(-r_s);
		g->camera.y = temp * sin(-r_s) + g->camera.y * cos(-r_s);
	}
	if (keycode == D)
	{
		temp = g->dir_vec.x;
		g->dir_vec.x = g->dir_vec.x * cos(r_s) - g->dir_vec.y * sin(r_s);
		g->dir_vec.y = temp * sin(r_s) + g->dir_vec.y * cos(r_s);
		temp = g->camera.x;
		g->camera.x = g->camera.x * cos(r_s) - g->camera.y * sin(r_s);
		g->camera.y = temp * sin(r_s) + g->camera.y * cos(r_s);
	}
}

//m_s is temp value | maybe change info -> frame move_speed
static void	move(int keycode, t_info *g)
{
	double	m_s;

	m_s = 1;
	if (keycode == W)
	{
		if (g->map[(int)(g->pos.x + g->dir_vec.x * m_s)][(int)(g->pos.y)] \
		== '0')
			g->pos.x += g->dir_vec.x * (m_s / 2);
		if (g->map[(int)(g->pos.x)][(int)(g->pos.y + g->dir_vec.y * m_s)] \
		== '0')
			g->pos.y += g->dir_vec.y * (m_s / 2);
	}
	if (keycode == S)
	{
		if (g->map[(int)(g->pos.x - g->dir_vec.x * m_s)][(int)(g->pos.y)] \
		== '0')
			g->pos.x -= g->dir_vec.x * (m_s / 2);
		if (g->map[(int)(g->pos.x)][(int)(g->pos.y - g->dir_vec.y * m_s)]\
		== '0')
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

//temp value maybe | m_s is move speed / r_s is rotate speed
int	key_press(int keycode, t_info *g)
{
	double	m_s;
	double	r_s;

	m_s = 0.5;
	r_s = PI / 36;
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
	if (keycode == K)
		mouse_vision(g);
	return (0);
}

int	exit_button(void)
{
	exit(0);
}
