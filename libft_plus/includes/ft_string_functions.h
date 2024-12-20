/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:05:55 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/12/19 10:09:54 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_FUNCTIONS_H
# define FT_STRING_FUNCTIONS_H

# include <stdlib.h>

void	ft_bzero(void *s, int size);
void	*ft_memchr(const void *s, int value, size_t n);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, void *src, size_t size);
void	*ft_memset(void *ptr, int value, size_t num);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *c);
int		ft_strncmp(const char *src, char *dest, size_t n);
char	*ft_strnstr(const char *src, const char *search, size_t len);
char	*ft_strrchr(const char *str, int c);

#endif
