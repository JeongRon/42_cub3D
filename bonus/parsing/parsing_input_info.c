/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:08:21 by jeongrol          #+#    #+#             */
/*   Updated: 2023/10/15 15:21:48 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	input_info_element_texture(char **tmp, t_info *info)
{
	if (ft_strcmp(tmp[0], "NO") == 0)
	{
		if (info->no)
			ft_error("file info-element-NO error");
		info->no = ft_strdup(tmp[1]);
	}
	else if (ft_strcmp(tmp[0], "SO") == 0)
	{
		if (info->so)
			ft_error("file info-element-SO error");
		info->so = ft_strdup(tmp[1]);
	}
	else if (ft_strcmp(tmp[0], "WE") == 0)
	{
		if (info->we)
			ft_error("file info-element-WE error");
		info->we = ft_strdup(tmp[1]);
	}
	else if (ft_strcmp(tmp[0], "EA") == 0)
	{
		if (info->ea)
			ft_error("file info-element-EA error");
		info->ea = ft_strdup(tmp[1]);
	}
	return (SUCCESS);
}

static int	input_info_element_color(char **tmp, t_info *info)
{
	char	**rgb;

	rgb = ft_split(tmp[1], ',');
	if (!rgb)
		ft_error ("MALLOC");
	if (ft_two_strlen(rgb) != 3)
	{
		ft_two_free(rgb);
		return (FAIL);
	}
	if (ft_strcmp(tmp[0], "F") == 0)
	{
		info->f[0] = ft_itoa(rgb[0]);
		info->f[1] = ft_itoa(rgb[1]);
		info->f[2] = ft_itoa(rgb[2]);
	}
	else if (ft_strcmp(tmp[0], "C") == 0)
	{
		info->c[0] = ft_itoa(rgb[0]);
		info->c[1] = ft_itoa(rgb[1]);
		info->c[2] = ft_itoa(rgb[2]);
	}
	ft_two_free(rgb);
	return (SUCCESS);
}

static void	input_info_element(char *line, t_info *info, int flag)
{
	char	**tmp;

	tmp = ft_split(line, ' ');
	if (!tmp)
		ft_error("MALLOC");
	if ((ft_strcmp(tmp[0], "NO") == 0 || ft_strcmp(tmp[0], "SO") == 0 \
		|| ft_strcmp(tmp[0], "WE") == 0 || ft_strcmp(tmp[0], "EA") == 0))
	{
		if (ft_two_strlen(tmp) == 2)
			flag = input_info_element_texture(tmp, info);
		else
			flag = FAIL;
	}
	else if ((ft_strcmp(tmp[0], "F") == 0 || ft_strcmp(tmp[0], "C") == 0))
	{
		if (ft_two_strlen(tmp) == 2)
			flag = input_info_element_color(tmp, info);
		else
			flag = FAIL;
	}
	ft_two_free(tmp);
	info->info_cnt++;
	if (flag == FAIL)
		ft_error("file info-element-input error");
}

static void	input_info_map(char *line, t_info *info)
{
	int		i;
	char	**tmp_map;

	i = ft_two_strlen(info->map);
	tmp_map = (char **)malloc(sizeof(char *) * (i + 2));
	if (!tmp_map)
		ft_error("MALLOC");
	i = 0;
	if (info->map)
	{
		while (info->map[i])
		{
			tmp_map[i] = ft_strdup(info->map[i]);
			i++;
		}
	}
	tmp_map[i] = ft_strdup(line);
	tmp_map[i + 1] = NULL;
	ft_two_free(info->map);
	info->map = ft_two_strdup(tmp_map);
	ft_two_free(tmp_map);
	info->info_cnt++;
}

void	input_info(char **av, t_info *info)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("file open error");
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		line = delete_new_line(line);
		line = replace_tab(line);
		if (check_empty_line(line) == SUCCESS && info->info_cnt <= 6)
			continue ;
		if (info->info_cnt < 6)
			input_info_element(line, info, 0);
		else
			input_info_map(line, info);
	}
	free(line);
	close(fd);
}
