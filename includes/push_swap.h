#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft_plus/includes/not_in_standard_includes/not_in_standard.h"
# include "../libft_plus/includes/not_in_standard_includes/ft_printf_bonus.h"

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

#endif