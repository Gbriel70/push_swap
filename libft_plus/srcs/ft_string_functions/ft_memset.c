/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:29:24 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/10/15 13:46:43 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_functions.h"

void	*ft_memset(void *ptr, int value, size_t num);

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	val;

	p = (unsigned char *)ptr;
	val = (unsigned char)value;
	i = 0;
	while (i < num)
	{
		p[i] = val;
		i++;
	}
	return (ptr);
}
