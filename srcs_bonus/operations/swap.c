/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:21:50 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/01/06 10:23:35 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_stack_a(t_stack *a)
{
	swap_top(a);
	ft_printf("sa\n");
}

void	swap_stack_b(t_stack *b)
{
	swap_top(b);
	ft_printf("sb\n");
}

void	swap_both_stacks(t_stack *a, t_stack *b)
{
	swap_top(a);
	swap_top(b);
	ft_printf("ss\n");
}

void	swap_top(t_stack *stack)
{
	int	i;

	if (stack->top <= 1)
		return ;
	i = stack->top - 1;
	ft_swap(&stack->items[i], &stack->items[i - 1]);
}
