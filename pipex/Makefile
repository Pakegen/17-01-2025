NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = utils/libft/

LIBFT_LIB = $(LIBFTDIR)/libft.a

SRC = src/main.c\
      src/child_utils.c\
      src/pipex.c\
      src/utils.c\
	  src/clean.c\
      src/file_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)


$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
