NAME = tester
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRC = tester_push_swap.c ../srcs/operations/rotate.c
LIBFT = -L../libft_plus -lft

all: push_swap $(NAME)
	./$(NAME)
	make --no-print fclean

push_swap:
	$(MAKE) -C ../

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) -lrt -lm $(LIBFT)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all push_swap clean fclean re