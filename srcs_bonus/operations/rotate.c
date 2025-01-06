/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:21:40 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/01/06 10:23:15 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_stack_a(t_stack *a)
{
	rotate_stack(a);
	ft_printf("ra\n");
}

void	rotate_stack_b(t_stack *b)
{
	rotate_stack(b);
	ft_printf("rb\n");
}

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_printf("rr\n");
}

void	rotate_stack(t_stack *stack)
{
	int	i;

	if (stack->top <= 1)
		return ;
	i = stack->top - 1;
	while (i > 0)
	{
		ft_swap(&stack->items[i], &stack->items[i - 1]);
		i--;
	}
}
