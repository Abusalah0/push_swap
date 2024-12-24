CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = init_prog.c main.c parallel_stack_ops.c  shared_stack_ops.c  stack_a_ops.c error_handling.c  input_parsing.c  node_ops.c  search_stacks.c \
	sorting.c stack_b_ops.c
SRCS = $(addprefix src/, $(SRC))
OBJSDIR = obj
OBJS = $(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.c=.o)))
NAME = push_swap
LIB_DIR = ./libft
LIB = $(LIB_DIR)/libft.a
LIB_FLAGS = -L$(LIB_DIR) -lft

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_FLAGS)

$(OBJSDIR)/%.o: src/%.c | $(OBJSDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

$(LIB):
	make -C $(LIB_DIR)

lib_clean:
	make -C $(LIB_DIR) clean

lib_fclean:
	make -C $(LIB_DIR) fclean

clean: lib_clean
	rm -rf $(OBJSDIR)

fclean: clean lib_fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean lib_clean lib_fclean clean all re
