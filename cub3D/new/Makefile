NAME		=	cub3D
CC			=	cc
FLAGS		=	-Wall -Werror -Wextra

LIBFT_DIR	=	./libftcore
LIBFT_A		=	$(LIBFT_DIR)/libftcore.a

MLX_DIR		=	./minilibx-linux
MLX_A		=	$(MLX_DIR)/libmlx.a

SRCS 		=	main.c ft_error.c \
				map_format_checker.c \
				parsing.c ft_realloc.c

OBJS 		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_A) $(MLX_A) $(OBJS)
	@echo "compiling $(NAME)..."
	$(CC) $(FLAGS) $(OBJS) $(LIBFT_A) $(MLX_A) -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

$(LIBFT_A):
	@echo "compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_A):
	@echo "compiling mlx..."
	@$(MAKE) -C $(MLX_DIR)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
