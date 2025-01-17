NAME = push_swap

SRCS_DIR = src
OBJS_DIR = obj

SRCS = $(addprefix $(SRCS_DIR)/, args_utils.c errors_utils.c list_utils.c \
                operations_basic.c operations_rotations.c sorting_utils.c \
                utils.c list_utils_2.c push_swap.c)

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@rmdir $(OBJS_DIR) 2>/dev/null || true

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
