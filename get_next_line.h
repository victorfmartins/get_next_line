/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:51:56 by vfranco-          #+#    #+#             */
/*   Updated: 2021/10/08 11:08:28 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*s;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_lstsize(t_list *lst);
int		ft_lst_new_addback_size(t_list **lst, void *s, int boo);
void	ft_lstclear(t_list **lst, void (*del)(void *));
char	*ft_strndup(const char *s1, size_t n);

#endif