/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:47:04 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/10/15 13:47:10 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "not_in_standard_includes/not_in_standard.h"

void	ft_putchar_fd(char c, int fd);

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
