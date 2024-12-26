#include "../../includes/push_swap.h"

void swap_stack_a(t_stack *a)
{
    swap_top(a);
    ft_printf("sa\n");
}

void swap_stack_b(t_stack *b)
{
    swap_top(b);
    ft_printf("sb\n");
}

void swap_both_stacks(t_stack *a, t_stack *b)
{
    swap_top(a);
    swap_top(b);
    ft_printf("ss\n");
}

void swap_top(t_stack *stack)
{
    int i;

    if (stack->top <= 1)
        return ;
    i = stack->top - 1;
    ft_swap(&stack->items[i], &stack->items[i - 1]);
}