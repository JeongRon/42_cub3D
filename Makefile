# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 18:16:30 by jeongrol          #+#    #+#              #
#    Updated: 2023/09/25 18:33:33 by jeongrol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HEADER	=	cub3d.h

MLX_LINK = -Lmlx -lmlx -framework OpenGL -framework Appkit

SRCS	=	cub3d.c \
			

OBJS	=	$(SRCS:%.c=%.o)

all:	$(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C mlx
	
fclean:	clean
	$(RM) $(NAME)

re:
	make fclean
	make all

$(NAME):	$(OBJS) $(HEADER)
	@make -C mlx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I. $(MLX_LINK)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:	all clean fclean re