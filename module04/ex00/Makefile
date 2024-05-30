
CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98
NAME		=	animals

SRC_PATH	=	src/
SRC			=	main.cpp \
				Animal.cpp \
				Dog.cpp \
				Cat.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp \

OBJ_PATH	=	obj/
OBJS		=	$(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))

INC_PATH	=	include/

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -I $(INC_PATH) -o $@ $(OBJS)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean:
	rm -rf $(OBJ_PATH)
	rm -f $(NAME)

re: fclean all
