# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 18:16:30 by jeongrol          #+#    #+#              #
#    Updated: 2023/10/09 20:11:36 by dongmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
MLX = -L ./mlx -lmlx -framework OpenGL -framework AppKit

RM = rm -f

HEADER	=	cub3d.h

# MLX_LINK = -Lmlx -lmlx -framework OpenGL -framework Appkit

SRCS	=	cub3d.c \
			get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_cub3d.c \
			parsing/parsing_cub3d.c \
			parsing/parsing_input_info.c \
			parsing/parsing_validate_info.c \
			utils/utils_cub3d.c \
			utils/utils_libft.c \
			utils/utils_split.c \
			excute/excute_draw_screen.c \
			excute/excute_hook.c \
			excute/excute_loop_hook.c \
			excute/excute_setting.c \
			excute/excute_utils.c \

OBJS	=	$(SRCS:%.c=%.o)

all:	$(NAME)

clean:
	make clean -C mlx
	$(RM) $(OBJS)
	
fclean:	clean
	$(RM) $(NAME)

re:
	make fclean
	make all

$(NAME):	$(OBJS) $(HEADER)
	make -C mlx/
	$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:	all clean fclean re