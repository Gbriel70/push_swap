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
    return (0);
}
