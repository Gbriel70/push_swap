/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:46:23 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/10/16 11:13:34 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_functions.h"

void	*ft_memcpy(void *dest, const void *src, size_t size);

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest == src)
		return (NULL);
	while (size--)
	{
		*d++ = *s++;
	}
	return (dest);
}
