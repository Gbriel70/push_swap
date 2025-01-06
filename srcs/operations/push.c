/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:58:21 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/01/06 10:03:51 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_to_stack_a(t_stack *b, t_stack *a)
{
	push_to_stack(b, a);
	ft_printf("pa\n");
}

void	push_to_stack_b(t_stack *a, t_stack *b)
{
	push_to_stack(a, b);
	ft_printf("pb\n");
}

void	push_to_stack(t_stack *origin, t_stack *reciver)
{
	if (origin->top == 0)
		return ;
	reciver->items[reciver->top] = origin->items[origin->top - 1];
	reciver->top++;
	origin->top--;
}
