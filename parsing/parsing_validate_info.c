/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validate_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:44:35 by jeongrol          #+#    #+#             */
/*   Updated: 2023/10/03 19:56:28 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
				if (info->pos_idx[0] == -1)
				{
					info->pos_idx[0] = x;
					info->pos_idx[1] = y;
					info->pos_dir = c;
				}
				else
					ft_error("file info-map error");
			}
			else
				ft_error("file info-map error");
		}
	}
	if (info->pos_idx[0] == -1)
		ft_error("file info-map position error");
}

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

// info-map 벽 둘러싸였는지 확인하는 함수 
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
				info->map[x][y] == 'E')
				search_surround_wall(info, x, y);
		}
	}
}
