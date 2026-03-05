NAME        = libftcore.a
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs

LIBFT_DIR   = libft
GNL_DIR     = gnl

LIBFT_A     = $(LIBFT_DIR)/libft.a
GNL_OBJS    = $(GNL_DIR)/get_next_line.o $(GNL_DIR)/get_next_line_utils.o

all: $(NAME)

$(NAME): $(LIBFT_A) $(GNL_OBJS)
	@echo "Building $(NAME)..."
	@mkdir -p .tmp_objs
	@cd .tmp_objs && ar x ../$(LIBFT_A)
	@$(AR) $(NAME) .tmp_objs/*.o $(GNL_OBJS)
	@rm -rf .tmp_objs
	@echo "$(NAME) ready!"

$(LIBFT_A):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning objects..."
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@rm -f $(GNL_OBJS)

fclean: clean
	@echo "Full clean..."
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re