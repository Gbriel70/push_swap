/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:59:14 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/01/06 10:02:08 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_cheapest_to_a(t_stack *b, t_stack *a, int n_position)
{
	int	target_position;

	target_position = find_target_position(a, b->items[n_position], b);
	if (target_position > a->top / 2 && n_position > b->top / 2)
	{
		while (target_position != a->top - 1 && n_position != b->top - 1)
		{
			rotate_both(a, b);
			n_position++;
			target_position++;
		}
	}
	else if (target_position < a->top / 2 && n_position < b->top / 2)
	{
		while (target_position >= 0 && n_position >= 0)
		{
			reverse_both_stacks(a, b);
			n_position--;
			target_position--;
		}
	}
	ft_move_to_top_b(b, &n_position);
	ft_move_to_top_a(a, &target_position);
	push_to_stack_a(b, a);
}

void	ft_move_to_top_a(t_stack *a, int *n_position)
{
	if (*n_position < a->top / 2)
	{
		while (*n_position >= 0)
		{
			reverse_stack_a(a);
			(*n_position)--;
		}
	}
	else
	{
		while (*n_position < a->top - 1)
		{
			rotate_stack_a(a);
			(*n_position)++;
		}
	}
}

void	ft_move_to_top_b(t_stack *b, int *n_position)
{
	if (*n_position < b->top / 2)
	{
		while (*n_position >= 0)
		{
			reverse_stack_b(b);
			(*n_position)--;
		}
	}
	else
	{
		while (*n_position < b->top - 1)
		{
			rotate_stack_b(b);
			(*n_position)++;
		}
	}
}

int	ft_get_min_pos(t_stack *stack)
{
	int	i;
	int	min_pos;

	i = 0;
	min_pos = i;
	while (i < stack->top)
	{
		if (stack->items[i] < stack->items[min_pos])
			min_pos = i;
		i++;
	}
	return (min_pos);
}

void	ft_turk_sort(t_stack *a, t_stack *b)
{
	int	n_position;
	int	min_position;

	while (a->top > 3)
		push_to_stack_b(a, b);
	ft_sort_3(a);
	while (b->top != 0)
	{
		n_position = find_the_least_expensive_number(a, b);
		push_cheapest_to_a(b, a, n_position);
	}
	min_position = ft_get_min_pos(a);
	ft_move_to_top_a(a, &min_position);
}
