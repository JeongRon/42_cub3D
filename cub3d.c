/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:14 by jeongrol          #+#    #+#             */
/*   Updated: 2023/09/30 19:26:55 by jeongrol         ###   ########.fr       */
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
	free_info(&info);
	return (0);
}
