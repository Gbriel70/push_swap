/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:53:42 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/10/16 14:39:31 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_functions.h"

char	*ft_strrchr(const char *str, int c);

char	*ft_strrchr(const char *str, int c)
{
	size_t	x;

	x = ft_strlen(str);
	while (x + 1)
	{
		if (str[x] == (char)c)
			return ((char *)&str[x]);
		x--;
	}
	return (NULL);
}
