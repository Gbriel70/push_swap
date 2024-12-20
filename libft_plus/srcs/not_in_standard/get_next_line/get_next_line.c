/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:46:59 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/12/19 10:12:37 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "not_in_standard_includes/get_next_line.h"

static void	read_line(t_line **str_cache, int fd);
static int	next_line(t_line *str_cache);
static void	create_line(t_line *str_cache, char **line);
static void	refact_line(t_line **str_cache);

char	*get_next_line(int fd)
{
	static t_line	*str_cache = NULL;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line(&str_cache, fd);
	if (!str_cache)
		return (NULL);
	create_line(str_cache, &line);
	refact_line(&str_cache);
	return (line);
}

static void	read_line(t_line **str_cache, int fd)
{
	int		output_r;
	char	*buffer_content;
	t_line	*new_chunk;

	output_r = 0;
	while (!next_line(*str_cache))
	{
		buffer_content = NULL;
		new_chunk = ft_lstnew(buffer_content);
		new_chunk->content = ft_calloc(sizeof(*buffer_content), BUFFER_SIZE
				+ 1);
		if (!new_chunk->content)
			return ;
		output_r = read(fd, new_chunk->content, BUFFER_SIZE);
		if (output_r <= 0)
		{
			free(new_chunk->content);
			free(new_chunk);
			if (output_r == -1)
				ft_lstclear(str_cache, free);
			return ;
		}
		new_chunk->content[BUFFER_SIZE] = '\0';
		ft_lstadd_back(str_cache, new_chunk);
	}
}

static int	next_line(t_line *str_cache)
{
	int	i;

	str_cache = ft_lstlast(str_cache);
	if (!str_cache)
		return (0);
	i = 0;
	while (str_cache->content[i] != '\0')
	{
		if (str_cache->content[i] == '\n')
		{
			str_cache->lenght = (i + 1);
			return (1);
		}
		i++;
	}
	str_cache->lenght = i;
	return (0);
}

static void	create_line(t_line *str_cache, char **line)
{
	int		line_size;
	t_line	*tmp;
	int		i;

	line_size = 0;
	tmp = str_cache;
	while (tmp)
	{
		line_size += tmp->lenght;
		tmp = tmp->next;
	}
	if (!line_size)
		return ;
	*line = malloc(sizeof(**line) * (line_size + 1));
	if (!line)
		return ;
	line_size = 0;
	while (str_cache && str_cache->content)
	{
		i = 0;
		while (str_cache->content[i] && i < str_cache->lenght)
			(*line)[line_size++] = str_cache->content[i++];
		str_cache = str_cache->next;
	}
	(*line)[line_size] = '\0';
}

static void	refact_line(t_line **str_cache)
{
	t_line	*tmp;
	t_line	*new_node;
	char	*content;
	int		size;
	int		i;

	size = 0;
	tmp = ft_lstlast(*str_cache);
	if (!tmp)
		return ;
	content = tmp->content;
	size = tmp->lenght;
	tmp->content = NULL;
	ft_lstclear(str_cache, free);
	if (content[size] != '\0')
	{
		i = 0;
		while (content[size] != '\0')
			content[i++] = content[size++];
		content[i] = '\0';
		new_node = ft_lstnew(content);
		ft_lstadd_back(str_cache, new_node);
	}
	else
		free(content);
}

// int	main(void)
// {
// 	int fd = open("teste.txt",O_RDONLY);
// 	if (fd < 0)
// 	{
// 		return (1);
// 	}
// 	char *line;

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
