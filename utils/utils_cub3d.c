/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:39:48 by jeongrol          #+#    #+#             */
/*   Updated: 2023/09/30 18:07:47 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_two_strlen(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_two_free(char **str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	ft_error(char *str)
{
	write(1, "ERROR\n", 6);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(0);
}

char	**ft_two_strdup(char **str)
{
	int		len;
	char	**tmp;
	int		i;

	len = ft_two_strlen(str);
	tmp = (char **)malloc(sizeof(char *) * (len + 1));
	i = -1;
	while (str[++i])
	{
		tmp[i] = ft_strdup(str[i]);
		if (!tmp[i])
			ft_error("MALLOC");
	}
	tmp[i] = NULL;
	return (tmp);
}

int	check_empty_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ' || line[i] == '\n')
			continue ;
		else
			return (FAIL);
	}
	return (SUCCESS);
}
