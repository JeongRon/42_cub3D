# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 18:16:30 by jeongrol          #+#    #+#              #
#    Updated: 2023/10/03 19:56:16 by jeongrol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HEADER	=	cub3d.h

# MLX_LINK = -Lmlx -lmlx -framework OpenGL -framework Appkit

SRCS	=	cub3d.c \
			get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line.c \
			parsing/parsing_cub3d.c \
			parsing/parsing_input_info.c \
			parsing/parsing_validate_info.c \
			utils/utils_cub3d.c \
			utils/utils_libft.c \
			utils/utils_split.c \

OBJS	=	$(SRCS:%.c=%.o)

all:	$(NAME)

clean:
	$(RM) $(OBJS)
	
fclean:	clean
	$(RM) $(NAME)

re:
	make fclean
	make all

$(NAME):	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:	all clean fclean re