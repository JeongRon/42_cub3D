/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validate_info_basic.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:44:35 by jeongrol          #+#    #+#             */
/*   Updated: 2023/10/15 00:37:20 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// info-element 유효성 검사 함수
void	validate_info_element(t_info *info)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (!((0 <= info->f[i] && info->f[i] <= 255) && \
			(0 <= info->c[i] && info->c[i] <= 255)))
			ft_error("file info-element-number error"); // f, c 배열 안의 값이 0~255 아니면 에러
	}
	if (ft_strcmp(info->no, info->so) == 0 || \
		ft_strcmp(info->no, info->we) == 0 || \
		ft_strcmp(info->no, info->ea) == 0 || \
		ft_strcmp(info->so, info->we) == 0 || \
		ft_strcmp(info->so, info->ea) == 0 || \
		ft_strcmp(info->we, info->ea) == 0)
		ft_error("file info-element-texture error"); // 동서남북 중복된 텍스처 있으면 에러
}

static void	input_pos_dir(t_info *info, int x, int y, char c)
{
	info->pos.x = x + 0.5;
	info->pos.y = y + 0.5;
	info->pos_dir = c;
	info->map[x][y] = '0';
}

// info-map 허용한 문자들 확인하는 함수
void	validate_info_map_char(t_info *info, int x, int y, char c)
{
	while (info->map[++x])
	{
		y = -1;
		while (info->map[x][++y])
		{
			c = info->map[x][y];
			if (c == ' ' || c == '0' || c == '1')
				continue ;
			else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				if (info->pos_dir == 'A')
					input_pos_dir(info, x, y, c);
				else
					ft_error("file info-map error");
			}
			else
				ft_error("file info-map error");
		}
	}
	if (info->pos_dir == 'A')
		ft_error("file info-map position error");
}
