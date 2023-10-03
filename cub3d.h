/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:19 by jeongrol          #+#    #+#             */
/*   Updated: 2023/10/03 18:45:26 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 42
# define FAIL 0
# define SUCCESS 1

typedef struct s_info
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	char	**map;
	int		info_cnt;
	int		pos_idx[2];
	char	pos_dir;
	int		row;
	int		col;
	int		dx[8];
	int		dy[8];
}	t_info;

// utils
// utils_libft.c
int		ft_strlen(const char *str);
char	*ft_strdup(const char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_itoa(char *str);
char	*ft_strjoin(char *buff, char *tmp, int tmp_len);
// utils_cub3d.c
int		ft_two_strlen(char **str);
void	ft_two_free(char **str);
void	ft_error(char *str);
char	**ft_two_strdup(char **str);
int		check_empty_line(char *line);
// utils_split.c
char	**ft_split(char const *str, char c);
// get_next_line
void	free_all(char *a, char *b);
int		ft_linelen(const char *s);
char	*delete_new_line(char *line);
char	*replace_tab(char *line);
char	*get_next_line(int fd);
// parsing
// parsing_cub3d.c
void	parsing_cub3d(int ac, char **av, t_info *info);
// parsing_set_info.c
void	input_info(char **av, t_info *info);

#endif