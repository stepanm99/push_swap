NAME = push_swap

SRC = push_swap.c src/arg_pars.c src/error.c src/linked_list.c leakcheck.c

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

DFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -static-libsan

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@"
	@$(CC) $(OBJ) $(DFLAGS) -o $(NAME)
	@echo "Done!"

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJB)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test