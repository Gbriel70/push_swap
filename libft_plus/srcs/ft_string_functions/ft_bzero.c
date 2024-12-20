/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:30:27 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/10/15 13:30:28 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_functions.h"

void	ft_bzero(void *s, int size);

void	ft_bzero(void *s, int size)
{
	int				i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < size)
	{
		p[i] = 0;
		i++;
	}
}
