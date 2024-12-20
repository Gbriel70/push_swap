/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:53:50 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/10/16 10:18:48 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "not_in_standard_includes/not_in_standard.h"
#include "ft_string_functions.h"

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	x;

	if (*s1 && set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	x = ft_strlen(s1);
	while (x && ft_strchr(set, s1[x]))
		x--;
	return (ft_substr(s1, 0, x + 1));
}
