NAME = push_swap

SRC = push_swap.c src/arg_pars.c src/error.c src/linked_list.c

CC = gcc

FLAGS = -Wall -Wextra -Werror -O3

DFLAGS = -Wall -Wextra -Werror -g

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@"
	@$(CC) $(OBJ) $(FLAGS) -o $(NAME)
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