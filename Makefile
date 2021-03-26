NAME = cub3D

HEADER = cub3d.h

SRCS =	parsing_cub_1.c \
		parsing_cub_2.c \
		parsing_cub_3.c \
		check_ciphers_1.c \
		check_ciphers_2.c \
		parsing_convert_1.c \
		parsing_convert_2.c \
		calculate_walls.c \
		draw_sprites.c \
		drawing.c \
		get_positions.c \
		get_texture_data.c \
		init_array_params.c \
		inits.c \
		errors.c \
		player_move.c \
		raycasting.c \
		screenshot.c \
		shortest_dist.c \
		sprites_calculations.c \
		sprites_data.c \
		wall_cross.c \
		utils.c \
		texture_valid.c \
		main.c \
		
OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

OBJ_DIR = obj
SRC_DIR = src
LIBFT_DIR = libft
LIBFT = libft.a
MLX_DIR = mlx
MLX = libmlx.dylib

CFLAGS = -Wall -Wextra -Werror -g

all:
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -j $(NAME)

$(NAME): $(OBJ) $(HEADER)
		@gcc $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_DIR) -l mlx -L $(LIBFT_DIR) -l ft
		@install_name_tool -change $(MLX) @loader_path/$(MLX_DIR)/$(MLX) $(NAME)
		@echo $(NAME) : Awesome, everyting has compiled

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(MLX_DIR)/$(MLX) $(LIBFT_DIR)/$(LIBFT)
		@mkdir -p $(OBJ_DIR)
		@gcc $(CFLAGS) -I $(MLX_DIR) -I $(LIBFT_DIR) -c $< -o $@

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -rf $(LIBFT_DIR)/$(LIBFT)
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re