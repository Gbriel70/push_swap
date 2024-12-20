/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:53:17 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/10/15 13:53:20 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_functions.h"

int	ft_strncmp(const char *src, char *dest, size_t n);

int	ft_strncmp(const char *src, char *dest, size_t n)
{
	size_t	i;

	if (n <= 0)
		return (0);
	i = 0;
	while (i < n && (src[i] != '\0' || dest[i] != '\0'))
	{
		if (src[i] != dest[i])
			return ((unsigned char)src[i] - (unsigned char)dest[i]);
		i++;
	}
	return (0);
}
