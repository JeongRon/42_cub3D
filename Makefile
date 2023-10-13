# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 18:16:30 by jeongrol          #+#    #+#              #
#    Updated: 2023/10/13 15:45:17 by dongmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
B_NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
MLX = -L ./mlx -lmlx -framework OpenGL -framework AppKit

RM = rm -f

HEADER	=	cub3d.h

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
			excute/excute_utils.c
			
B_SRCS	=	bonus/cub3d.c \
			get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_cub3d.c \
			bonus/parsing/parsing_cub3d.c \
			bonus/parsing/parsing_input_info.c \
			bonus/parsing/parsing_validate_info.c \
			utils/utils_cub3d.c \
			utils/utils_libft.c \
			utils/utils_split.c \
			bonus/excute/excute_draw_screen.c \
			bonus/excute/excute_minimap.c \
			bonus/excute/excute_hook.c \
			bonus/excute/excute_loop_hook.c \
			bonus/excute/excute_setting.c \
			bonus/excute/excute_utils.c \
			bonus/excute/excute_door_event.c
			
B_OBJS	=	$(B_SRCS:%.c=%.o)

OBJS	=	$(SRCS:%.c=%.o)

ifdef WITH_BONUS
    OBJ = $(B_OBJS)
else
    OBJ = $(OBJS)
endif

all:	$(NAME)

bonus:
	@make WITH_BONUS:=1 all

clean:
	make clean -C mlx
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)
	
fclean:	clean
	$(RM) $(NAME)

re:
	make fclean
	make all

$(NAME): $(OBJ) $(HEADER)
	make -C mlx/
	$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJ)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:	all clean fclean re bonus