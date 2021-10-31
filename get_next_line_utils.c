/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 11:55:32 by vfranco-          #+#    #+#             */
/*   Updated: 2021/10/31 12:05:21 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	c = (unsigned char) c;
	while (*s != c && *s != '\0')
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	n;
	size_t	i;

	if (!s1)
		return (NULL);
	n = ft_strlen(s1);
	s2 = malloc(sizeof(char) * n + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)s2)[i] = ((unsigned char *)s1)[i];
		i++;
	}
	((unsigned char *)s2)[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	len_s1;
	unsigned int	len_s2;
	char			*join;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (i++ < len_s1)
		join[i - 1] = s1[i - 1];
	i = 0;
	while (i++ < len_s2)
		join[i + len_s1 - 1] = s2[i - 1];
	join[len_s1 + len_s2] = '\0';
	return (join);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	idx;

	if (!src)
		return (0);
	if (size == 0)
		return (ft_strlen((char *)src));
	idx = 0;
	while (src[idx] != '\0' && idx < size - 1)
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *str)
{
	size_t	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}
