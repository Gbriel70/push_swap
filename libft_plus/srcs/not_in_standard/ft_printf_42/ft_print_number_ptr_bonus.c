/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_ptr_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:30:35 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/12/19 10:18:19 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "not_in_standard_includes/ft_printf_bonus.h"

static int	len_str(char *str);

int	ft_print_number(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
		count += ft_print_number(nbr / 10);
	count += ft_printchar((nbr % 10) + '0');
	return (count);
}

int	ft_putnbr_base(long int nbr, char *base)
{
	int	c;
	int	len_base;

	c = 0;
	len_base = len_str(base);
	if (nbr < 0)
	{
		c += ft_printchar('-');
		nbr *= -1;
	}
	if (nbr >= len_base)
		c += ft_putnbr_base(nbr / len_base, base);
	c += ft_printchar(base[nbr % len_base]);
	return (c);
}

static int	len_str(char *str)
{
	char	*len;

	len = str;
	while (*len)
		len++;
	return (len - str);
}

int	ft_print_pointer(unsigned long ptr, char *base)
{
	int	i;
	int	len_base;

	i = 0;
	len_base = len_str(base);
	if (ptr == 0)
		return (ft_printstr("(nil)"));
	if (ptr >= (unsigned long)len_base)
		i += ft_print_pointer(ptr / len_base, base);
	else
		i += ft_printstr("0x");
	i += ft_printchar(base[ptr % len_base]);
	return (i);
}
