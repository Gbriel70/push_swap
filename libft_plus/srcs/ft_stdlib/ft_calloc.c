/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:31:26 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/12/19 10:08:19 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string_functions.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;
	size_t	t_size;

	if (num != 0 && size > SIZE_MAX / num)
		return (NULL);
	t_size = size * num;
	p = malloc(t_size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, t_size);
	return (p);
}
