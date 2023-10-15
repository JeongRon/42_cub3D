# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 18:16:30 by jeongrol          #+#    #+#              #
#    Updated: 2023/10/15 15:07:15 by jeongrol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
B_NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -L ./mlx -lmlx -framework OpenGL -framework AppKit

RM = rm -f

HEADER	=	cub3d.h

SRCS	=	mandatory/cub3d.c \
			get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_cub3d.c \
			mandatory/parsing/parsing_cub3d.c \
			mandatory/parsing/parsing_input_info.c \
			mandatory/parsing/parsing_validate_info_basic.c \
			mandatory/parsing/parsing_validate_info_detail.c \
			utils/utils_cub3d.c \
			utils/utils_libft.c \
			utils/utils_split.c \
			mandatory/excute/excute_draw_screen.c \
			mandatory/excute/excute_hook.c \
			mandatory/excute/excute_loop_hook.c \
			mandatory/excute/excute_setting.c \
			mandatory/excute/excute_utils.c
			
B_SRCS	=	bonus/cub3d.c \
			get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_cub3d.c \
			bonus/parsing/parsing_cub3d.c \
			bonus/parsing/parsing_input_info.c \
			bonus/parsing/parsing_validate_info_basic.c \
			bonus/parsing/parsing_validate_info_detail.c \
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