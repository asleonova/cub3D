# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/05 12:46:16 by dbliss            #+#    #+#              #
#    Updated: 2020/08/05 13:57:28 by dbliss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
HEADER = cub3d.h
LIBFT = ./libft_master/libft.a
LIBFT_DIR = ./libft_master
SRCS = start.c \
	get_next_line.c \
	get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
		gcc -c -Wall -Wextra -Werror $< -o $@ 
		
all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C $(LIBFT_DIR)
		cp $(LIBFT) $(NAME)
		ar rc $(NAME) $(OBJS)
clean:
		rm -f $(OBJS)
fclean: 
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re