NAME = libft.a
CC = gcc
FT_PRINTF = ./ft_printf
GNL = ./GNL
FT_STRING = ./ft_string
CFLAGS = -Wall -Wextra -Werror
SRCS = 		$(FT_STRING)/ft_atoi.c $(FT_STRING)/ft_bzero.c $(FT_STRING)/ft_isalnum.c $(FT_STRING)/ft_isalpha.c $(FT_STRING)/ft_isascii.c $(FT_STRING)/ft_isdigit.c $(FT_STRING)/ft_isprint.c \
			$(FT_STRING)/ft_memchr.c $(FT_STRING)/ft_memcmp.c $(FT_STRING)/ft_memcpy.c $(FT_STRING)/ft_memmove.c $(FT_STRING)/ft_memset.c \
			$(FT_STRING)/ft_strchr.c $(FT_STRING)/ft_strlcat.c $(FT_STRING)/ft_strlcpy.c $(FT_STRING)/ft_strlen.c $(FT_STRING)/ft_strncmp.c $(FT_STRING)/ft_strnstr.c $(FT_STRING)/ft_strrchr.c \
			$(FT_STRING)/ft_tolower.c $(FT_STRING)/ft_toupper.c \
			$(FT_STRING)/ft_strdup.c $(FT_STRING)/ft_calloc.c $(FT_STRING)/ft_substr.c $(FT_STRING)/ft_strjoin.c $(FT_STRING)/ft_strtrim.c $(FT_STRING)/ft_split.c $(FT_STRING)/ft_itoa.c $(FT_STRING)/ft_strmapi.c $(FT_STRING)/ft_striteri.c\
			$(FT_STRING)/ft_putchar_fd.c $(FT_STRING)/ft_putstr_fd.c $(FT_STRING)/ft_putendl_fd.c $(FT_STRING)/ft_putnbr_fd.c\
			$(FT_STRING)/ft_lstnew.c $(FT_STRING)/ft_lstsize.c $(FT_STRING)/ft_lstadd_front.c $(FT_STRING)/ft_lstadd_back.c $(FT_STRING)/ft_lstlast.c\
			$(FT_PRINTF)/ft_printf.c $(FT_PRINTF)/ft_printf_helper.c $(FT_PRINTF)/ft_printf_func.c $(FT_PRINTF)/ft_printf_hexa.c\
			$(GNL)/get_next_line_bonus.c $(GNL)/get_next_line_utils_bonus.c

OBJS = 	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs	$(NAME) $(OBJS)

%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME) 

re: fclean all
