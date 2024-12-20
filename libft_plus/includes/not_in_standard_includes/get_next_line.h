/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:47:54 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/12/19 10:10:04 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_line
{
	char			*content;
	int				lenght;
	struct s_line	*next;
}	t_line;

char	*get_next_line(int fd);
t_line	*ft_lstnew(char *content);
t_line	*ft_lstlast(t_line *lst);
void	ft_lstadd_back(t_line **lst, t_line *new);
void	ft_lstclear(t_line **lst, void (*del)(void *));
void	*ft_calloc(size_t num, size_t size);

#endif
