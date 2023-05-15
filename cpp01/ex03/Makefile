# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 16:44:51 by caboudar          #+#    #+#              #
#    Updated: 2023/05/15 16:44:52 by caboudar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	HumanA.cpp \
				HumanB.cpp \
				Weapon.cpp \
				main.cpp \

OBJS		=	$(SRCS:%.cpp=%.o)

CC			=	c++

RM			=	rm -f

CFLAGS		= 	-Wall -Wextra -Werror -I./

CPPFLAGS	= 	-std=c++98

NAME		= 	ex01

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