/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:52:26 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/10/15 13:52:28 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "not_in_standard_includes/not_in_standard.h"
#include "ft_string_functions.h"

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_concat;
	size_t	concat_size;
	size_t	x;

	concat_size = ft_strlen(s1) + ft_strlen(s2);
	str_concat = malloc(concat_size + 1);
	if (!str_concat)
		return (NULL);
	x = 0;
	while (*s1)
	{
		str_concat[x++] = *s1++;
	}
	while (*s2)
	{
		str_concat[x++] = *s2++;
	}
	str_concat[x] = '\0';
	return (str_concat);
}
