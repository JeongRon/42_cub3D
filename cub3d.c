/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:14 by jeongrol          #+#    #+#             */
/*   Updated: 2023/10/09 20:30:45 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_info(t_info *info)
{
	free(info->no);
	free(info->so);
	free(info->we);
	free(info->ea);
	ft_two_free(info->map);
}

int	main(int ac, char **av)
{
	t_info	info;
	parsing_cub3d(ac, av, &info);
	// TEST_CODE 넣는 자리
	setting_mlx(&info);


	//excution
	mlx_hook(info.win, KEY_EVENT_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, KEY_EVENT_EXIT, 0, &exit_button, &info);
	mlx_loop_hook(info.mlx, &draw_loop, &info);
	mlx_loop(info.mlx);
	free_info(&info);
	return (0);
}
