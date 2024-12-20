/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:46:33 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/10/16 11:09:29 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_functions.h"

void	*ft_memmove(void *dest, void *src, size_t size);

void	*ft_memmove(void *dest, void *src, size_t size)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest == src)
		return (dest);
	if (d < s)
	{
		while (size--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d += size;
		s += size;
		while (size--)
		{
			*(--d) = *(--s);
		}
	}
	return (dest);
}
