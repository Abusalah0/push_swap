CC = cc
CFLAGS = -Wall -Wextra -Werror
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
			search_stacks.c \
			hashset.c \

BONUS_SRCS = $(addprefix src/, $(BONUS_SRC))
BONUS_OBJSDIR = obj_bonus
BONUS_OBJS = $(addprefix $(BONUS_OBJSDIR)/, $(notdir $(BONUS_SRCS:.c=.o)))

NAME = push_swap
BONUS_NAME = checker_bonus
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

bonus: $(BONUS_OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LIB_FLAGS)

$(BONUS_OBJSDIR)/%.o: src/%.c | $(BONUS_OBJSDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJSDIR):
	mkdir -p $(BONUS_OBJSDIR)

$(LIB):
	make -C $(LIB_DIR)

lib_clean:
	make -C $(LIB_DIR) clean

lib_fclean:
	make -C $(LIB_DIR) fclean

clean: lib_clean
	rm -rf $(OBJSDIR)

clean_bonus: lib_clean
	rm -rf $(BONUS_OBJSDIR)

fclean: clean lib_fclean
	rm -rf $(NAME)

fclean_bonus: clean lib_fclean clean_bonus
	rm -rf $(BONUS_NAME)
re: fclean all

re_bonus: fclean_bonus bonus

.PHONY: fclean lib_clean lib_fclean clean all re bonus fclean_bonus clean_bonus re_bonus
