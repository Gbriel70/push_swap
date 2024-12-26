# include "../../includes/push_swap.h"

void reverse_stack_a(t_stack *a)
{
    reverse_stacks(a);
    ft_printf("rra\n");
}

void reverse_stack_b(t_stack *b)
{
    reverse_stacks(b);
    ft_printf("rrb\n");
}

void reverse_both_stacks(t_stack *a, t_stack *b)
{
    reverse_stacks(a);
    reverse_stacks(b);
    ft_printf("rrr\n");
}

void reverse_stacks(t_stack *stack)
{
    int i;

    if (stack->top <= 1)
        return ;
    i = 0;
    while (i < stack->top - 1)
    {
        ft_swap(&stack->items[i], &stack->items[i + 1]);
        i++;
    }
}
