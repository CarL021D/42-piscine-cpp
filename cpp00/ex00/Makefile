# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 16:41:54 by caboudar          #+#    #+#              #
#    Updated: 2023/05/15 16:41:55 by caboudar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	megaphone.cpp \

OBJS		=	$(SRCS:%.cpp=%.o)

CC			=	c++

RM			=	rm -f

CFLAGS		= 	-Wall -Wextra -Werror -I./

CPPFLAGS	= 	-std=c++98

NAME		= 	ex00

%.o: %.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME)	

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re bonus