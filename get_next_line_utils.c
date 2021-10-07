/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:45:22 by vfranco-          #+#    #+#             */
/*   Updated: 2021/09/29 10:43:25 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lst_new_addback_size(t_list **lst, void *s, int boo)
{
	t_list	*p;
	t_list	*new;
	size_t	size;

	new = malloc(sizeof(t_list));
	if (!lst || !new)
		return (0);
	(*new).s = s;
	(*new).next = NULL;
	size = 0;
	if (!(*lst) && !boo && ++size)
		*lst = new;
	else if ((*lst))
	{
		p = *lst;
		while (++size && p->next)
			p = p->next;
		if (!boo && ++size)
			p->next = new;
	}
	if (boo)
		free(new);
	return (size);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*p_next;

	if (!lst || !del)
		return ;
	p = *lst;
	while (p)
	{
		p_next = p->next;
		del(p->s);
		free(p);
		p = p_next;
	}
	*lst = NULL;
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

char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char) c;
	while (*s != c && *s != '\0')
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (n * (len >= n) + len * (len < n) + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < (n * (len >= n) + len * (len < n)))
	{
		((unsigned char *)s2)[i] = ((unsigned char *)s1)[i];
		i++;
	}
	((unsigned char *)s2)[i] = '\0';
	return (s2);
}
