NAME = push_swap

SRC = push_swap.c src/arg_pars.c src/error.c src/linked_list.c \
	src/push_operations.c src/rev_rotate_operations.c src/rotate_operations.c \
	src/swap_operations.c src/rotate_operations_utils.c src/sort.c \
	src/rev_rotate_operations_utils.c src/k_sort.c src/linked_list_free.c \
	src/linked_list_duplicate.c src/simple_sort.c src/bubble_sort.c \
	src/better_sort.c src/simple_sort_find_min_index_rev.c \
	src/simple_sort_find_min_index.c src/better_sort_rangefinder.c \
	src/better_sort_to_buckets.c src/better_sort_to_a.c \
	src/data_init_and_free.c

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

DFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -static-libsan

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@"
	@$(CC) $(OBJ) $(FLAGS) -o $(NAME)
	@echo "Done!"

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(FLAGS) -c $< -o $@

debug: $(OBJ)
	@echo "Debug compiling"
	@$(CC) $(OBJ) -Wall -Wextra -Werror -g -o $(NAME)
	@echo "Done!"

leak: $(OBJ)
	@echo "Leak compiling"
	@$(CC) $(SRC) leakcheck.c $(FLAGS) -o $(NAME)
	@echo "Done!"

sanitize: $(OBJ)
	@echo "Sanitize compiling"
	@$(CC) $(OBJ) $(DFLAGS) -o $(NAME)
	@echo "Done!"

clean:
	@rm -f $(OBJ) $(OBJB)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test