#==================================FLAGS======================================#

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFT_FLAG = -L$(LIB_PATH) -lft
MAKE_NO_PRINT = $(MAKE) --no-print-directory

#================================PATHS=========================================#

LIB_PATH = ./libft_plus/
HEADER_PATH = ./includes
SRC_PATH = ./srcs
BONUS_PATH = ./srcs_bonus

#================================FILES=========================================#

#MANDATORY
NAME = push_swap
BONUS_NAME = checker
SRC = $(wildcard $(SRC_PATH)/*.c) $(wildcard $(SRC_PATH)/operations/*.c)
OBJ = $(SRC:.c=.o)
HEADER = $(HEADER_PATH)/push_swap.h

#BONUS
SRC_BONUS = $(wildcard $(BONUS_PATH)/*.c) $(wildcard $(BONUS_PATH)/operations/*.c)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
HEADER_BONUS = $(HEADER_PATH)/push_swap_bonus.h

#================================RULES=========================================#

all: libft $(NAME)

libft:
	$(MAKE_NO_PRINT) -C $(LIB_PATH)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_FLAG)

$(SRC_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: libft $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_BONUS) $(HEADER_BONUS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJ_BONUS) $(LIBFT_FLAG)

$(BONUS_PATH)/%.o: $(BONUS_PATH)/%.c $(HEADER_BONUS)
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

#================================SET LIB=================================#

set:
	git submodule update --init --recursive

#================================GDB===========================================#

gdb:
	@echo "ARG: Stack of numbers"
	gdb ./$(NAME) $(ARG)

#================================CLEAN=========================================#

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	$(MAKE_NO_PRINT) clean -C $(LIB_PATH)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE_NO_PRINT) fclean -C $(LIB_PATH)

re: fclean all

rebonus: fclean bonus

.PHONY: all libft run leak tests gdb clean fclean re rebonus