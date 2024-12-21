#include "../includes/push_swap.h"

void ft_free_matrix(char **array, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        free(array[i]);
        i++;
    }
    free(array);
}

void ft_handle_errors(t_stack *a, t_stack *b, int stage, char **n_matrix)
{
    int i;

    i = 0;
    if (n_matrix != NULL)
    {
        while (n_matrix[i])
            i++;
        ft_free_matrix(n_matrix, i);
    }
    if (stage >= 1)
    {
        free(a->items);
        if (stage >= 2)
            free(b->items);
    }
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}