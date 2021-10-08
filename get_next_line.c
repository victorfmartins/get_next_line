/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:28:27 by vfranco-          #+#    #+#             */
/*   Updated: 2021/10/08 11:10:06 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
#define INT_MAX 2147483647

void	ft_strncat(char *dest, char *src, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	if (!src)
		return ;
	while (src[idx] && idx < n)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
}

char	*ft_lststrjoin(t_list *lst, char *buffer)
{
	int		size;
	int		count;
	char	*line;
	char	*after_n;
	t_list	*p;

	size = ft_lst_new_addback_size(&lst, "", 1);
	after_n = ft_strchr(buffer, '\n');
	if (size == 0)
	{
		line = ft_strndup(buffer, after_n - buffer + 1);
		return (line);
	}
	if (after_n)
		count = after_n - buffer + ft_strlen((char *)(lst->s));
	else
		count = ft_strlen((char *)(lst->s)) + ft_strlen(buffer);
	line = malloc(sizeof(char) * ((size - 1) * BUFFER_SIZE + count + 2));
	if (!line)
		return (NULL);
	p = lst;
	count = 0;
	while (p)
	{
		ft_strncat(line + count, p->s, ft_strlen((char *)(p->s)));
		count = count + ft_strlen((char *)(p->s));
		p = p->next;
	}
	ft_strncat(line + count, buffer, after_n - buffer + 1);
	return (line);
}

char	*ft_read_more(t_list **lst, int fd)
{
	int		num_read;
	char	*buffer;
	char	*buffer_aux;
	char	*line;

	buffer = "";
	line = NULL;
	while (!ft_strchr(buffer, '\n') && (!line || ft_strchr(line, '\n') != 0))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		num_read = read(fd, buffer, BUFFER_SIZE);
		if (num_read <= 0)
		{
			free(buffer);
			if (ft_lst_new_addback_size(lst, NULL, 1) != 0)
			{
				line = ft_lststrjoin(*lst, NULL);
				ft_lstclear(lst, &free);
				return (line);
			}
			return (NULL);
		}
		buffer[num_read] = '\0';
		if (ft_strchr(buffer, '\n') || num_read != BUFFER_SIZE)
		{
			line = ft_lststrjoin(*lst, buffer);
			if (ft_strchr(buffer, '\n'))
				buffer_aux = ft_strndup(ft_strchr(buffer, '\n') + 1, INT_MAX);
			else
				buffer_aux = ft_strndup("", INT_MAX);
			if (!buffer_aux)
				return (NULL);
			ft_lstclear(lst, &free);
			if (buffer_aux[0] != '\0')
				ft_lst_new_addback_size(lst, buffer_aux, 0);
			else
				free(buffer_aux);
		}
		else
			ft_lst_new_addback_size(lst, buffer, 0);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static t_list	*lst;
	char			*line;

	if (lst && ft_strchr(lst->s, '\n'))
	{
		line = ft_strndup(lst->s, ft_strchr(lst->s, '\n') - (char *)lst->s + 1);
		if (!line)
			return (NULL);
		buffer = ft_strndup(ft_strchr(lst->s, '\n') + 1, INT_MAX);
		if (!buffer)
			return (NULL);
		if (ft_strlen(buffer))
		{
			ft_lstclear(&lst, &free);
			if (buffer[0] != '\0')
				ft_lst_new_addback_size(&lst, buffer, 0);
			else
				free(buffer);
		}
		else
		{
			free(buffer);
			ft_lstclear(&lst, &free);
		}
	}
	else
		line = ft_read_more(&lst, fd);
	return (line);
}

// int	main()
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("song.txt", O_RDONLY);
// 	line = "";
// 	while (line) // chances muito baixas (ou nula) de free em line resul em nulo
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		write(1, line, ft_strlen(line));
// 		free(line);
// 	}
// }

// Parameters File descriptor to read from
// Return value Read line: correct behavior
// NULL: nothing else to read or an error occurred
// External functs. read, malloc, free
// Description Write a function which returns a line read from a
// file descriptor
