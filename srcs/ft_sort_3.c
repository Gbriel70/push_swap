#include "../includes/push_swap.h"

int ft_get_max_pos(t_stack *stack)
{
    int i;
    int max_pos;

    i = 0;
    max_pos = i;
    while (i < stack->top)
    {
        if (stack->items[i] > stack->items[max_pos])
            max_pos = i;
        i++;
    }
    return (max_pos);
}


void ft_sort_3(t_stack *a)
{
    int min_position;
    int max_position;

    if (check_if_sorted(a) == 0)
        return ;
    min_position = ft_get_min_pos(a);
    max_position = ft_get_max_pos(a);
    if (min_position == a->top - 1)
    {
        swap_stack_a(a);
        rotate_stack_a(a);
    }
    else if (max_position == a->top - 1)
    {
        rotate_stack_a(a);
        if (min_position == 0)
            swap_stack_a(a);
    }
    else
    {
        if (max_position == 0)
            swap_stack_a(a);
        else
            reverse_stack_a(a);
    }
}