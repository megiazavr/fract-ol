NAME = fractol

SRC = points.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./lib/minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)
MLX_FLAGS = -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(SRC)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(SRC) $(MLX_LIB) $(MLX_INC) $(MLX_FLAGS) -o $(NAME)

clean:
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
