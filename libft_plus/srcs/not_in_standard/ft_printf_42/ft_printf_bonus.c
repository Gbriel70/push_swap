/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:25:09 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/12/19 10:20:18 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "not_in_standard_includes/ft_printf_bonus.h"

static int	check_value(char input, va_list args, char flag)
{
	int	total;

	total = 0;
	if (input == 'c')
		total += ft_printchar(va_arg(args, int));
	else if (input == 's')
		total += ft_printstr(va_arg(args, char *));
	else if (input == 'p')
		total += ft_print_pointer(va_arg(args, unsigned long),
				HEXADECIMAL_BASE);
	else if (input == 'd' || input == 'i')
		total += ft_putplus_and_space(va_arg(args, int), DECIMAL_BASE, flag);
	else if (input == 'u')
		total += ft_putnbr_base(va_arg(args, unsigned int), DECIMAL_BASE);
	else if (input == 'x')
		total += put_hexa(va_arg(args, unsigned int), HEXADECIMAL_BASE, flag);
	else if (input == 'X')
		total += put_hexa(va_arg(args, unsigned int), UPER_HEXADECIMAL_BASE,
				flag);
	else if (input == '%')
		total += ft_printchar('%');
	return (total);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		print_l;
	int		i;

	if (!input)
		return (-1);
	print_l = 0;
	va_start(args, input);
	i = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			while (input[i] == '#' || input[i] == ' ' || input[i] == '+')
				i++;
			print_l += check_value(input[i], args, input[i - 1]);
		}
		else
			print_l += ft_printchar(input[i]);
		i++;
	}
	va_end(args);
	return (print_l);
}

// #include <stdio.h>
// int main()
// {
//  	ft_printf("meu teste: % 1s .", "");
//  	printf("\n");
//  	printf("teste % 1s .", "");
// 	return (0);
// }
