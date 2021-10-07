# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 11:11:13 by vfranco-          #+#    #+#              #
#    Updated: 2021/09/28 11:11:14 by vfranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libgnl.a

FILES		=	get_next_line.c \
				get_next_line_utils.c

FLAGS		=	-Wall -Wextra -Werror

OBJ			=	$(FILES:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

%.o:	%.c
			clang -c $(FLAGS) $<

clean:
			rm -f $(OBJ)

fclean:	clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
