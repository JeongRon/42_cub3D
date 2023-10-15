/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validate_info_detail.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:27:19 by jeongrol          #+#    #+#             */
/*   Updated: 2023/10/15 15:22:19 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	search_surround_wall(t_info *info, int x, int y)
{
	int	i;
	int	nx;
	int	ny;

	i = -1;
	while (++i < 8)
	{
		nx = x + info->dx[i];
		ny = y + info->dy[i];
		if ((0 <= nx && nx < info->row) && (0 <= ny && ny < info->col))
		{
			if (info->map[nx][ny] == ' ')
				ft_error("file info-map-wall error");
			else
				continue ;
		}
		else
			ft_error("file info-map-wall error");
	}
}

void	validate_info_map_wall(t_info *info, int x, int y)
{
	while (info->map[++x])
	{
		y = -1;
		while (info->map[x][++y])
		{
			if (info->map[x][y] == ' ' || info->map[x][y] == '1')
				continue ;
			else if (info->map[x][y] == '0' || info->map[x][y] == 'N' || \
				info->map[x][y] == 'S' || info->map[x][y] == 'W' || \
				info->map[x][y] == 'E' || info->map[x][y] == 'D')
				search_surround_wall(info, x, y);
		}
	}
}

void	validate_info_map_emptyline(t_info *info, int x, int y, int flag)
{
	int	empty_flag;

	empty_flag = 0;
	while (info->map[++x])
	{
		flag = 0;
		if (info->map[x][0] == '\0')
		{
			empty_flag = 1;
			continue ;
		}
		y = -1;
		while (info->map[x][++y])
		{
			if (info->map[x][y] != ' ')
			{
				flag = 1;
				break ;
			}
		}
		if (flag != 1)
			empty_flag = 1;
		if (empty_flag == 1 && flag == 1)
			ft_error("MAP EMPTYLINE");
	}
}
