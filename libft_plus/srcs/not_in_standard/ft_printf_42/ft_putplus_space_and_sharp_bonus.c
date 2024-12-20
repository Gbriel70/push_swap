/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putplus_space_and_sharp_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:35:22 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/12/19 10:18:44 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "not_in_standard_includes/ft_printf_bonus.h"

static int	ft_strcmp(char *str1, char *str2);

int	ft_putplus_and_space(long int nbr, char *base, char flag)
{
	int	total;

	total = 0;
	if ((flag == '+') && (nbr >= 0))
		total += ft_printchar('+');
	if ((flag == ' ') && (nbr >= 0))
		total += ft_printchar(' ');
	total += ft_putnbr_base(nbr, base);
	return (total);
}

int	put_hexa(long int nbr, char *base, char flag)
{
	int	total;

	total = 0;
	if ((flag == '#') && (nbr > 0))
	{
		if (ft_strcmp(base, "0123456789abcdef"))
			total += ft_printstr("0X");
		if (ft_strcmp(base, "0123456789ABCDEF"))
			total += ft_printstr("0x");
	}
	total += ft_putnbr_base(nbr, base);
	return (total);
}

static int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
