/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:29:43 by jeongrol          #+#    #+#             */
/*   Updated: 2023/09/30 19:36:04 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// 인자 확인하는 함수
static void	check_ac_av(int ac, char **av)
{
	int	len;

	if (ac != 2)
		ft_error("ac error"); // 인자 오직 둘 이상이면 에러
	len = ft_strlen(av[1]);
	if (len <= 4)
		ft_error("file name error"); // 파일 이름 길이 4 이하면 에러
	if (!(av[1][len - 4] == '.' && av[1][len - 3] == 'c' &&
		av[1][len - 2] == 'u' && av[1][len - 1] == 'b'))
		ft_error("file name error"); // ~.cub 파일 형식으로 작성 안되어있으면 에러
}

// info 구조체 초기화 함수
static void	initialize_info(t_info *info)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		info->f[i] = -1;
		info->c[i] = -1;
	}
	info->no = NULL;
	info->so = NULL;
	info->we = NULL;
	info->ea = NULL;
	info->map = NULL;
	info->info_cnt = 0;
	info->pos_idx[0] = -1;
	info->pos_idx[1] = -1;
	info->pos_dir = 'A';
}

// info-element 유효성 검사 함수
static void	validate_info_element(t_info *info)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (!((0 <= info->f[i] && info->f[i] <= 255) && \
			(0 <= info->c[i] && info->c[i] <= 255)))
			ft_error("file info-element error"); // f, c 배열 안의 값이 0~255 아니면 에러
	}
	if (ft_strcmp(info->no, info->so) == 0 || \
		ft_strcmp(info->no, info->we) == 0 || \
		ft_strcmp(info->no, info->ea) == 0 || \
		ft_strcmp(info->so, info->we) == 0 || \
		ft_strcmp(info->so, info->ea) == 0 || \
		ft_strcmp(info->we, info->ea) == 0)
		ft_error("file info-element error"); // 동서남북 중복된 텍스처 있으면 에러
}

// info-map 허용한 문자들 확인하는 함수
static void	validate_info_map_char(t_info *info, int x, int y)
{
	char	c;

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
}

// info-map 벽(1) 둘러싸였는지 확인하는 함수 
// static void	validate_info_map_wall(t_info *info)
// {
	
// }

void	parsing_cub3d(int ac, char **av, t_info *info)
{
	check_ac_av(ac, av);
	initialize_info(info);
	input_info(av, info);
	validate_info_element(info);
	validate_info_map_char(info, -1, -1);
	// validate_info_map_wall(info);
}
