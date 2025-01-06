/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:21:57 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/01/06 10:22:02 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_handle_errors(t_stack *a, t_stack *b, int stage, char **n_matrix)
{
	int	i;

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

int	check_if_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top - 1)
	{
		if (a->items[i] > a->items[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_free_matrix(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	exec_operation(char *operation, t_stack *a, t_stack *b)
{
	if (ft_strncmp(operation, "pa\n", 3) == 0)
		push_to_stack_a(b, a);
	else if (ft_strncmp(operation, "pb\n", 3) == 0)
		push_to_stack_b(a, b);
	else if (ft_strncmp(operation, "sa\n", 3) == 0)
		swap_stack_a(a);
	else if (ft_strncmp(operation, "sb\n", 3) == 0)
		swap_stack_b(b);
	else if (ft_strncmp(operation, "ss\n", 3) == 0)
		swap_both_stacks(a, b);
	else if (ft_strncmp(operation, "ra\n", 3) == 0)
		rotate_stack_a(a);
	else if (ft_strncmp(operation, "rb\n", 3) == 0)
		rotate_stack_b(b);
	else if (ft_strncmp(operation, "rr\n", 3) == 0)
		rotate_both(a, b);
	else if (ft_strncmp(operation, "rra\n", 4) == 0)
		reverse_stack_a(a);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
		reverse_stack_b(b);
	else if (ft_strncmp(operation, "rrr\n", 4) == 0)
		reverse_both_stacks(a, b);
	else
		ft_handle_errors(a, b, 3, NULL);
}

void	exec_and_check_instructions(t_stack *a, t_stack *b)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation != NULL)
	{
		exec_operation(operation, a, b);
		free(operation);
		operation = get_next_line(0);
	}
	if (check_if_sorted(a) == 1 || b->top != 0)
	{
		free(a->items);
		free(b->items);
		ft_printf("KO\n");
		exit(EXIT_FAILURE);
	}
}
