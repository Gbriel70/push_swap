/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:57:29 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/01/06 09:57:33 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft_plus/includes/ft_string_functions.h"
# include "../libft_plus/includes/not_in_standard_includes/ft_printf_bonus.h"
# include "../libft_plus/includes/not_in_standard_includes/get_next_line.h"
# include "../libft_plus/includes/not_in_standard_includes/not_in_standard.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	size_max;
	int	top;
	int	*items;
}		t_stack;

char	**parse_argv(int ac, char **av);
void	init_stacks(t_stack *a, t_stack *b, char **init_matrix);
int		mega_atoi(const char *m_index, t_stack *a, t_stack *b,
			char **init_matrix);
void	check_duplicates(t_stack *a, t_stack *b);

void	ft_handle_errors(t_stack *a, t_stack *b, int stage, char **n_matrix);
int		check_if_sorted(t_stack *a);
void	ft_free_matrix(char **array, int size);
void	exec_operation(char *operation, t_stack *a, t_stack *b);
void	exec_and_check_instructions(t_stack *a, t_stack *b);

// FUNCTIONS TO OPERATE STACKS

// FUNCTIONS TO SWAP ELEMENTS
void	swap_top(t_stack *stack);
void	swap_stack_a(t_stack *a);
void	swap_stack_b(t_stack *b);
void	swap_both_stacks(t_stack *a, t_stack *b);

// FUNCTIONS TO PUSH ELEMENTS
void	push_to_stack(t_stack *origin, t_stack *reciver);
void	push_to_stack_a(t_stack *b, t_stack *a);
void	push_to_stack_b(t_stack *a, t_stack *b);

// FUNCTIONS TO ROTATE ELEMENTS
void	rotate_stack(t_stack *stack);
void	rotate_stack_a(t_stack *a);
void	rotate_stack_b(t_stack *b);
void	rotate_both(t_stack *a, t_stack *b);

// FUNCTIONS TO REVERSE ELEMENTS
void	reverse_stacks(t_stack *stack);
void	reverse_stack_a(t_stack *a);
void	reverse_stack_b(t_stack *b);
void	reverse_both_stacks(t_stack *a, t_stack *b);

#endif