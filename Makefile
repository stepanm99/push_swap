NAME = push_swap

SRC = push_swap.c src/arg_pars.c src/error.c src/linked_list.c \
	src/push_operations.c src/rev_rotate_operations.c src/rotate_operations.c \
	swap_operations.c

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

DFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -static-libasan

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