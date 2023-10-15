/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:46:08 by jeongrol          #+#    #+#             */
/*   Updated: 2023/10/15 15:26:00 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		src_len;
	char	*temp;
	int		i;

	src_len = ft_strlen(src);
	temp = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!temp)
		ft_error("MALLOC");
	i = 0;
	while (src[i] != '\0')
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_itoa(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (1)
	{
		if ('0' <= str[i] && str[i] <= '9')
			num = (num * 10) + (str[i] - '0');
		else
			break ;
		i++;
	}
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != '\0')
		return (-1);
	return (num);
}

char	*ft_strjoin(char *buff, char *tmp, int tmp_len)
{
	char	*join_buff;
	int		buff_len;
	int		i;

	buff_len = ft_strlen(buff);
	join_buff = (char *)malloc(sizeof(char) * (buff_len + tmp_len + 1));
	if (!join_buff)
		return (NULL);
	i = 0;
	while (i < buff_len)
	{
		join_buff[i] = buff[i];
		i++;
	}
	i = 0;
	while (i < tmp_len)
	{
		join_buff[buff_len + i] = tmp[i];
		i++;
	}
	join_buff[buff_len + i] = '\0';
	free(buff);
	return (join_buff);
}
