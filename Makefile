# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/05 12:46:16 by dbliss            #+#    #+#              #
#    Updated: 2020/10/05 16:50:03 by dbliss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

HEADER = cub3d.h

SRCS = ./src/main.c \
	./src/inits.c \
	./src/drawing.c \
	./src/calculations.c \
	./src/player_move.c \
	./src/raycasting.c \
	./src/sprites.c


OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c -g

LIBFT_ARC = libft/libft.a
MLX_ARC = ./mlx/libmlx.a

		
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_ARC) $(MLX_ARC)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -Llibft -lft $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -Ilibft $< -o $@

$(LIBFT_ARC):
	make -C libft

$(MLX_ARC):
	make -C mlx

clean:
	make clean -C libft
	rm -f $(OBJS)
fclean: clean
	make fclean -C libft
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re