#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft_plus/includes/not_in_standard_includes/not_in_standard.h"

typedef struct s_stack
{
    int size_max;
    int top;
    int *items;
}   t_stack;



#endif