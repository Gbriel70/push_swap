/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:59:01 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/01/06 10:01:40 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_target_position(t_stack *a, int num, t_stack *b)
{
	int	*stack_cpy;
	int	i;
	int	target_position;

	stack_cpy = sort_cpy_stack(a);
	if (stack_cpy == NULL)
		ft_handle_errors(a, b, 3, NULL);
	i = a->top - 1;
	while (i >= 0 && num > stack_cpy[i])
		i--;
	if (i < 0)
		i = a->top - 1;
	target_position = a->top - 1;
	while (a->items[target_position] != stack_cpy[i])
		target_position--;
	free(stack_cpy);
	return (target_position);
}

int	*sort_cpy_stack(t_stack *a)
{
	int	*stack_cpy;
	int	i;
	int	j;

	stack_cpy = ft_calloc(a->top, sizeof(int));
	if (stack_cpy == NULL)
		return (NULL);
	stack_cpy = ft_memcpy(stack_cpy, a->items, a->top * sizeof(int));
	i = 0;
	while (i < a->top - 1)
	{
		j = i + 1;
		while (j < a->top)
		{
			if (stack_cpy[i] < stack_cpy[j])
				ft_swap(&stack_cpy[i], &stack_cpy[j]);
			j++;
		}
		i++;
	}
	return (stack_cpy);
}

int	cost_to_target(t_stack *a, t_stack *b, int num_position,
		int target_position)
{
	int	moves;

	moves = 0;
	if (target_position > a->top / 2 && num_position > b->top / 2)
	{
		while (target_position != a->top - 1 && num_position != b->top - 1)
		{
			moves++;
			num_position++;
			target_position++;
		}
	}
	else if (target_position < a->top / 2 && num_position < b->top / 2)
	{
		while (target_position >= 0 && num_position >= 0)
		{
			moves++;
			num_position--;
			target_position--;
		}
	}
	moves += cost_to_top(b, &num_position);
	moves += cost_to_top(a, &target_position);
	return (moves + 1);
}

int	cost_to_top(t_stack *stack, int *num_position)
{
	int	median;
	int	moves;

	median = stack->top / 2;
	moves = 0;
	if (*num_position < median)
	{
		while (*num_position >= 0)
		{
			moves++;
			(*num_position)--;
		}
	}
	else
	{
		while (*num_position < stack->top - 1)
		{
			moves++;
			(*num_position)++;
		}
	}
	return (moves);
}

int	find_the_least_expensive_number(t_stack *a, t_stack *b)
{
	int	*movement_cost;
	int	i;
	int	target_position;
	int	cheapest_position;

	movement_cost = ft_calloc(b->top, sizeof(int));
	if (movement_cost == NULL)
		ft_handle_errors(a, b, 3, NULL);
	i = 0;
	while (i < b->top)
	{
		target_position = find_target_position(a, b->items[i], b);
		movement_cost[i] = cost_to_target(a, b, i, target_position);
		i++;
	}
	cheapest_position = --i;
	while (i >= 0)
	{
		if (movement_cost[cheapest_position] > movement_cost[i])
			cheapest_position = i;
		i--;
	}
	free(movement_cost);
	return (cheapest_position);
}
