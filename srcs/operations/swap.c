#include "../include/push_swap.h"

void swap_stack_a(t_stack *a)
{
    ft_swap_top(a);
    ft_printf("sa\n");
}

void swap_top(t_stack *stack)
{
    int i;

    if (stack->top <= 1)
        return ;
    i = stack->top - 1;
    ft_swap(&stack->items[i], &stack->items[i - 1]);
}