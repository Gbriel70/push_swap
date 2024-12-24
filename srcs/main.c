#include "../includes/push_swap.h"

char **process_av(int ac, char **av)
{
    int i;
    char *n_str;
    char *tmp;
    char **matrix;

    i = 1;
    n_str = ft_strdup(av[i]);
    while (++i < ac)
    {
        tmp = ft_strjoin(n_str, " ");
        free(n_str);
        if (tmp == NULL)
            return (NULL);
        n_str = ft_strjoin(tmp, av[i]);
        free(tmp);
        if (n_str == NULL)
            return (NULL);
    }
    matrix = ft_split(n_str, ' ');
    free(n_str);
    return (matrix);
}

void init_stacks(t_stack *a, t_stack *b, char **init_matrix)
{
    int count;
    int i;

    count = 0;
    while (init_matrix[count])
        count++;
    a->size_max = count;
    a->top = count;
    a->items = ft_calloc(count + 1, sizeof(int));
    if (a->items == NULL)
        ft_handle_errors(a, b, 0, init_matrix);
    b->size_max = count;
    b->top = 0;
    b->items = ft_calloc(count + 1, sizeof(int));
    if (b->items == NULL)
        ft_handle_errors(a, b, 1, init_matrix);
    i = 0;
    while (count > 0)
    {
        a->items[i] = mega_atoi(init_matrix[count - 1], a, b, init_matrix);
        i++;
        count--;
    }
    ft_free_matrix(init_matrix, i);
}

int mega_atoi(const char *m_index, t_stack *a, t_stack *b, char **init_matrix)
{
    unsigned char i;
    int sign;
    int nbr;

    i = 0;
    while (m_index[i] == ' ' || m_index[i] == '\t' || m_index[i] == '\n'
            || m_index[i] == '\v' || m_index[i] == '\f' || m_index[i] == '\r')
        i++;
    sign = 1;
    if (m_index[i] == '-')
        sign = -1;
    if (m_index[i] == '-' || m_index[i] == '+')
        i++;
    if (m_index[i] == '\0')
        ft_handle_errors(a, b, 2, init_matrix);
    nbr = 0;
    while (m_index[i] >= '0' && m_index[i] <= '9')
        nbr = nbr * 10 + (m_index[i++] - '0');
    if (m_index[i] != '\0' && (m_index[i] < '0' || m_index[i] > '9'))
        ft_handle_errors(a, b, 2, init_matrix);
    nbr *= sign;
    if (nbr < INT_MIN || nbr > INT_MAX)
        ft_handle_errors(a, b, 3, init_matrix);
    return (nbr);
}

void check_duplicates(t_stack *a, t_stack *b)
{
    int i;
    int j;

    i = 0;
    while (i < a->top - 1)
    {
        j = i + 1;
        while (j < a->top)
        {
            if (a->items[i] != a->items[j])
                j++;
            else
                ft_handle_errors(a, b, 4, NULL);
        }
        i++;
    }
}

int main(int ac, char **av)
{
    char **init_matrix;
    t_stack a;
    t_stack b;

    if (ac == 1)
        return (EXIT_FAILURE);
    if (av[1][0] == '\0')
    {
        write(2, "Error\n", 6);
        exit(EXIT_FAILURE);
    }
    init_matrix = process_av(ac, av);
    if (init_matrix == NULL)
        ft_handle_errors(&a, &b, 0, NULL);
    init_stacks(&a, &b, init_matrix);
    check_duplicates(&a, &b);
    if (check_if_sorted(&a) == 1)
        ft_turk_sort(&a, &b);
    free(a.items);
    free(b.items);
    return (0);
}
