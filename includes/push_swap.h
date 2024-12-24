#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft_plus/includes/not_in_standard_includes/not_in_standard.h"
# include "../libft_plus/includes/not_in_standard_includes/ft_printf_bonus.h"
# include "../libft_plus/includes/ft_string_functions.h"
# include "../libft_plus/includes/ft_stdlib.h"

typedef struct s_stack
{
    int size_max;
    int top;
    int *items;
}   t_stack;

//FUNCTIONS TO OPERATE STACKS

//FUNCTIONS TO SWAP ELEMENTS
void swap_top(t_stack *stack);
void swap_stack_a(t_stack *a);
void swap_stack_b(t_stack *b);
void swap_both_stacks(t_stack *a, t_stack *b);

//FUNCTIONS TO PUSH ELEMENTS
void push_to_stack(t_stack *origin, t_stack *reciver);
void push_to_stack_a(t_stack *b, t_stack *a);
void push_to_stack_b(t_stack *a, t_stack *b);

//FUNCTIONS TO ROTATE ELEMENTS
void rotate_stack(t_stack *stack);
void rotate_stack_a(t_stack *a);
void rotate_stack_b(t_stack *b);
void rotate_both(t_stack *a, t_stack *b);

//FUNCTIONS TO REVERSE ELEMENTS
void reverse_stacks(t_stack *stack);
void reverse_stack_a(t_stack *a);
void reverse_stack_b(t_stack *b);
void reverse_both_stacks(t_stack *a, t_stack *b);

//FUNCTIONS TO CHECK ERRORS
void ft_free_matrix(char **array, int size);
void ft_handle_errors(t_stack *a, t_stack *b, int stage, char **n_matrix);

//FUCNTIONS UTILS
void init_stacks(t_stack *a, t_stack *b, char **init_matrix);
int mega_atoi(const char *m_index, t_stack *a, t_stack *b, char **init_matrix);
void check_duplicates(t_stack *a, t_stack *b);
int check_if_sorted(t_stack *a);

//FUNCTIONS TO SORT
void ft_sort_3(t_stack *a);
void ft_turk_sort(t_stack *a, t_stack *b);
int ft_get_min_pos(t_stack *stack);
int ft_get_max_pos(t_stack *stack);

//FUNCTIONS TO FIND CHEAPEST
int find_the_least_expensive_number(t_stack *a, t_stack *b);
int cost_to_top(t_stack *stack, int *num_pos);
int cost_to_target(t_stack *a, t_stack *b, int num_position, int target_position);
int *sort_cpy_stack(t_stack *a);
int find_target_position(t_stack *a, int num, t_stack *b);
int cost_to_top(t_stack *stack, int *num_pos);
void push_cheapest_to_a(t_stack *b, t_stack *a, int n_position);
void ft_move_to_top_a(t_stack *a, int *n_position);
void ft_move_to_top_b(t_stack *b, int *n_position);

#endif