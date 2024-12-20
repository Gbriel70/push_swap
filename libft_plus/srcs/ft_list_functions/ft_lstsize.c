/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:42:58 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/10/15 13:43:01 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_functions.h"

int	ft_lstsize(t_list *lst);

int	ft_lstsize(t_list *lst)
{
	size_t	lst_size;

	lst_size = 0;
	while (lst)
	{
		lst = lst->next;
		lst_size++;
	}
	return (lst_size);
}
