CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = main.c\
	parallel_stack_ops.c \
	error_handling.c \
	input_parsing.c \
	sort_helpers_for_a.c \
	stack_ops.c \
	sorting.c \
	node_ops.c \
	sort_helpers_for_b.c \
	a_stack_ops.c \
	b_stack_ops.c \
	search_stacks.c \
	hashset.c \

SRCS = $(addprefix src/, $(SRC))
OBJSDIR = obj
OBJS = $(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.c=.o)))
BONUS_SRC = checker_bonus.c \
			parallel_stack_ops.c \
			error_handling.c \
			input_parsing.c \
			sort_helpers_for_a.c \
			stack_ops.c \
			sorting.c \
			node_ops.c \
			sort_helpers_for_b.c \
			a_stack_ops.c \
			b_stack_ops.c \
			search_stacks.c
			
BONUS_SRCS = $(addprefix src/, $(BONUS_SRC))
BONUS_OBJS = $(addprefix $(OBJSDIR)/, $(notdir $(BONUS_SRCS:.c=.o)))
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

bonus: $(BONUS_OBJS) $(LIB)
	$(CC) $(CFLAGS) -o checker_bonus $(BONUS_OBJS) $(LIB_FLAGS) $(LIB_FLAGS)

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
