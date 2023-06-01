NAME = minishell

SOURCES = main.c

LIBFT = libft.a
LIBFT_PATH = libft
LIBFT_MAKE = $(MAKE) -C $(LIBFT_PATH)

OBJ = $(SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT_PATH)/$(LIBFT)
	$(CC) $(OBJ) -L$(LIBFT_PATH) -lft -lreadline -o $(NAME)
	@echo "\033[32mCompiled OK!\033[0m"

$(LIBFT):
	$(LIBFT_MAKE)

clean:
	$(RM) $(OBJ)
	$(LIBFT_MAKE) clean
	@echo "\033[33mclean OK!\033[0m"

fclean: clean
	$(RM) $(NAME)
	$(LIBFT_MAKE) fclean
	find . -name '*.a' -delete
	@echo "\033[32mRemoved all files!\033[0m"
	
re: fclean all

.PHONY: all clean fclean re