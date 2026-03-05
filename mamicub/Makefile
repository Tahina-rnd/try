NAME = cub3D

INCLUDE_DIR	= include

LIBFT_DIR = libft
LIBFT_A =	$(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_A =	$(MLX_DIR)/libmlx.a

KEYCONFIG_DIR = ./utils/keyconfig/
RENDER_DIR = ./utils/render/
WINDOW_DIR = ./utils/window/

KEYCONFIG_FUNC =	$(KEYCONFIG_DIR)keypress.c \
					$(KEYCONFIG_DIR)move_action.c \

RENDER_FUNC =	$(RENDER_DIR)draw_minimap.c \
				$(RENDER_DIR)draw_texture.c \
				$(RENDER_DIR)test.c \

WINDOW_FUNC = 	$(WINDOW_DIR)open_window.c \
				$(WINDOW_DIR)close_window.c \

UTILS = $(KEYCONFIG_FUNC) $(RENDER_FUNC) $(WINDOW_FUNC)

SRCS_DIR = src
SRCS = ./main.c $(UTILS)

OBJS =	$(SRCS:.c=.o)
OBJS_DIR = ./obj
OBJS_KEYCONFIG_DIR = ./obj/utils/keyconfig/
OBJS_RENDER_DIR = ./obj/utils/render/
OBJS_WINDOW_DIR = ./obj/utils/window/

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(INCLUDE_DIR) -I$(MLX_DIR) -g

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_KEYCONFIG_DIR)
	@mkdir -p $(OBJS_RENDER_DIR)
	@mkdir -p $(OBJS_WINDOW_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT_A):
	@echo "\033[33m Compiling libft...\033[0m"
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_A):
	@echo "Compiling MiniLibX..."
	$(MAKE) -C $(MLX_DIR)

$(NAME):  $(addprefix $(OBJS_DIR)/, $(OBJS)) $(LIBFT_A) $(MLX_A)
	@echo "\033[33m Compiling $(NAME)...\033[0m"
	$(CC) $(CFLAGS) -o $@ $^ -Lminilibx-linux -lmlx -lXext -lX11 -lm

clean:
	@rm -rf $(OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	@echo "\033[31m file.o removed\033[0m"

fclean: clean
	@rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	@echo "\033[31m file.o and binary removed \033[0m"

re: fclean all

.PHONY: all clean fclean re
