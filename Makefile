#==================================FLAGS======================================#

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFT_FLAG = -L$(LIB_PATH) -lft
MAKE_NO_PRINT = $(MAKE) --no-print-directory

#================================PATHS=========================================#

LIB_PATH = ./libft_plus/
HEADER_PATH = ./includes
SRC_PATH = ./srcs

#================================FILES=========================================#

NAME = push_swap
SRC = $(wildcard $(SRC_PATH)/*.c) $(wildcard $(SRC_PATH)/operations/*.c)
OBJ = $(SRC:.c=.o)
HEADER = $(HEADER_PATH)/push_swap.h

#================================RULES=========================================#

all: libft $(NAME)

libft:
	$(MAKE_NO_PRINT) -C $(LIB_PATH)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_FLAG)

$(SRC_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

run:
	@echo "ARG: Stack of numbers"
	./$(NAME) $(ARG)

#================================LEAKS=========================================#

leak:
	@echo "ARG: Stack of numbers"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes ./$(NAME) $(ARG)

#================================TESTER========================================#

tests:
	@./try_do_my_tests/test.sh $(tests) $(nbrs)

#================================GDB===========================================#

gdb:
	@echo "ARG: Stack of numbers"
	gdb ./$(NAME) $(ARG)

#================================CLEAN=========================================#

clean:
	rm -f $(OBJ)
	$(MAKE_NO_PRINT) clean -C $(LIB_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE_NO_PRINT) fclean -C $(LIB_PATH)

.PHONY: all libft run leak gdb clean fclean