/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 22:18:41 by vfranco-          #+#    #+#             */
/*   Updated: 2021/10/31 22:22:54 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_join(int fd, char *backup)
{
	char	*buffer;
	char	*swap;
	int		num_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		if (ft_strchr(backup, '\n'))
			break ;
		num_read = read(fd, buffer, BUFFER_SIZE);
		if (num_read <= 0)
			break ;
		buffer[num_read] = '\0';
		swap = ft_strdup(backup);
		free(backup);
		backup = ft_strjoin(swap, buffer);
		free(swap);
	}
	free(buffer);
	return (backup);
}

char	*extract_line(char **backup)
{
	char	*line;
	char	*aux;
	int		i;

	i = 0;
	while ((*backup)[i] != '\n' && (*backup)[i] != '\0')
		i++;
	line = malloc(sizeof(char) * i + 2);
	ft_strlcpy(line, *backup, i + 2);
	aux = *backup;
	if ((*backup)[i] != '\0' &&
		!((*backup)[i] == '\n' && (*backup)[i + 1] == '\0' ))
		*backup = ft_strdup((*backup) + i + 1);
	else
		*backup = NULL;
	free(aux);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_and_join(fd, backup);
	if (!backup)
		return (NULL);
	line = extract_line(&backup);
	return (line);
}
