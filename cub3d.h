/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:19 by jeongrol          #+#    #+#             */
/*   Updated: 2023/10/09 16:44:30 by dongmiki         ###   ########.fr       */
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

//Key fuction
# define KEY_ESC 53
# define KEY_EVENT_PRESS 2
# define KEY_EVENT_EXIT 17
# define A			0
# define S			1
# define D			2
# define W			13

//Math
# define PI 3.14159265359

typedef struct s_img
{
	void	*img;
	int		*data;
	int		bpp;
	int		line_size;
	int		width;
	int		height;
	int		endian;
}	t_img;

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_frame
{
	double	time;
	double	old_time;
}	t_frame;

typedef struct s_info
{
	void		*mlx;
	void		*win;
	// delete
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	//	-->	t_img		map_texture[4];
	int			f[3];
	int			c[3];
	int			info_cnt;
	int			pos_idx[2];
	char		pos_dir;
	int			dx[8];
	int			dy[8];
	//excute
	int			row;
	int			col;
	char		**map;
	t_vec2		dir_vec;
	t_vec2		pos;
	t_vec2		camera;
	t_img		img;//mini_map no useable madatory
	t_img		screen;
	t_img		map_texture[4];
	t_frame		frame;
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
char	*get_next_line(int fd);
void	free_all(char *a, char *b);
int		ft_linelen(const char *s);
char	*delete_new_line(char *line);
char	*replace_tab(char *line);
// parsing
// parsing_cub3d.c
void	parsing_cub3d(int ac, char **av, t_info *info);
// parsing_set_info.c
void	input_info(char **av, t_info *info);
// parsing_validate_info_map.c
void	validate_info_element(t_info *info);
void	validate_info_map_char(t_info *info, int x, int y, char c);
void	validate_info_map_wall(t_info *info, int x, int y);
// excute_hook
int		key_press(int keycode, t_info *g);
int		exit_button(void);
// excute_loop_hook
int		draw_loop(t_game *game);


#endif