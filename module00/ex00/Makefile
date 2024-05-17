# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 15:13:34 by nsalles           #+#    #+#              #
#    Updated: 2024/05/02 14:50:02 by nsalles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98
NAME		=	megaphone

SRC_PATH	=	src/
SRC			=	megaphone.cpp

OBJ_PATH	=	obj/
OBJS		=	$(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean:
	rm -rf $(OBJ_PATH)
	rm -f $(NAME)

re: fclean all
