/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:14 by jeongrol          #+#    #+#             */
/*   Updated: 2023/10/15 15:25:30 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_info	info;

	parsing_cub3d(ac, av, &info);
	setting_mlx(&info, -1);
	info.ani = 0;
	info.ani_time = 0;
	mlx_hook(info.win, KEY_EVENT_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, KEY_EVENT_EXIT, 0, &exit_button, &info);
	mlx_loop_hook(info.mlx, &draw_loop, &info);
	mlx_loop(info.mlx);
}
