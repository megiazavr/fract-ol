# **************************************************************************** #
#                              FRACT-OL MAKEFILE                              #
# **************************************************************************** #

NAME = fractol
CC	= cc
CFLAGS	= -Wall -Wextra -Werror

SRC_DIR	= .
MLX_DIR	= minilibx-linux
LIBFT_DIR = libft

MLX_LIB		= $(MLX_DIR)/libmlx.a
LIBFT_LIB	= $(LIBFT_DIR)/libft.a
MLX_FLAGS	= -I $(MLX_DIR) -lXext -lX11 -lm
INCLUDES	= -I$(MLX_DIR) -I$(LIBFT_DIR) -I.

SRC	= main.c mandelbrot.c julia.c zoom.c utils.c key_press.c close_w.c
OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): libft mlx $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(MLX_LIB) $(INCLUDES) $(MLX_FLAGS) -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft:
	@$(MAKE) -C $(LIBFT_DIR)

mlx:
	git clone https://github.com/42paris/minilibx-linux.git $(MLX_DIR);
	@$(MAKE) -C $(MLX_DIR) all

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re libft mlx
