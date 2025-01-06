/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:58:53 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/01/06 10:01:03 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
