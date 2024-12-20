/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:53:26 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/10/15 14:22:12 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_functions.h"

char	*ft_strnstr(const char *src, const char *search, size_t len);

char	*ft_strnstr(const char *src, const char *search, size_t len)
{
	size_t	i;
	size_t	j;

	if (search[0] == '\0')
		return ((char *)src);
	i = 0;
	while (i < len && src[i] != '\0')
	{
		if (src[i] == search[0])
		{
			j = 0;
			while (search[j] && src[i + j] == search[j] && (i + j) < len)
			{
				j++;
			}
			if (search[j] == '\0')
				return ((char *)&src[i]);
		}
		i++;
	}
	return (NULL);
}
