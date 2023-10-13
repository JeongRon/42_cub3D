/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:57:22 by dongmiki          #+#    #+#             */
/*   Updated: 2023/10/13 14:41:45 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	ft_abs(double num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ndst;
	unsigned char	*nsrc;

	ndst = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	if (ndst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ndst[i] = nsrc[i];
		i++;
	}
	return (ndst);
}

void	mouse_event(t_info *game)
{
	int	x;
	int	y;

	if (game->mouse == 0)
		return ;
	mlx_mouse_get_pos(game->win, &x, &y);
	if (x > 690)
		rotate(D, game);
	else if (x < 590)
		rotate(A, game);
	mlx_mouse_move(game->win, 640, 480);
}

int	mouse_event2(int keycode, int x, int y, t_info *game)
{
	double	temp;

	(void)x;
	(void)y;
	if (keycode == LEFT_CLICK)
		game->ani_time++;
	if (keycode == RIGHT_CLICK)
	{
		temp = game->dir_vec.x;
		game->dir_vec.x = game->dir_vec.x * \
		cos(-PI) - game->dir_vec.y * sin(-PI);
		game->dir_vec.y = temp * sin(-PI) + game->dir_vec.y * cos(-PI);
		temp = game->camera.x;
		game->camera.x = game->camera.x * cos(-PI) - game->camera.y * sin(-PI);
		game->camera.y = temp * sin(-PI) + game->camera.y * cos(-PI);
	}
	return (0);
}
