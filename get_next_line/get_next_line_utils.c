/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:11:34 by jeongrol          #+#    #+#             */
/*   Updated: 2023/09/30 19:13:11 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_all(char *a, char *b)
{
	free(a);
	free(b);
}

int	ft_linelen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

int	check_new_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (SUCCESS);
		i++;
	}
	return (FAIL);
}

char	*delete_new_line(char *line)
{
	int		new_line_flag;
	int		i;
	char	*tmp;

	new_line_flag = check_new_line(line);
	if (new_line_flag == FAIL)
		return (line);
	i = ft_strlen(line);
	tmp = (char *)malloc(sizeof(char) * i);
	if (!tmp)
		ft_error("MALLOC");
	tmp[--i] = '\0';
	while (--i != -1)
		tmp[i] = line[i];
	free(line);
	return (tmp);
}

char	*replace_tab(char *line)
{
	char	*tmp;
	int		tab_cnt;
	int		i;
	int		j;
	int		k;

	tab_cnt = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == '\t')
			tab_cnt++;
	}
	if (tab_cnt == 0)
		return (line);
	tmp = (char *)malloc(sizeof(char) * (i + (tab_cnt * 7)));
	if (!tmp)
		ft_error("MALLOC");
	i = 0;
	j = 0;
	k = 0;
	while (line[i])
	{
		if (line[i] == '\t')
		{
			k = 0;
			while (k < 8)
			{
				tmp[j + k] = ' ';
				k++;
			}
			i += 1;
			j += 8;
		}
		else
		{
			tmp[j] = line[i];
			i += 1;
			j += 1;
		}
	}
	tmp[j] = '\0';
	free(line);
	return (tmp);
}
