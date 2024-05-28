
CC				=	c++
CFLAGS			=	-Wall -Werror -Wextra --std=c++98
NAME			=	bsp

SRC				=	main.cpp \
					Fixed.cpp \
					Point.cpp \
					bsp.cpp \

MLX				=	libmlx.a

OBJ				=	$(SRC:.cpp=.o)

OBJ_PATH		=	obj/
SRC_PATH		=	src/
MLX_PATH		=	minilibx-linux/

SRCS			=	$(addprefix $(SRC_PATH), $(SRC))
OBJS			=	$(addprefix $(OBJ_PATH), $(OBJ))
MLXS			=	$(addprefix $(MLX_PATH), $(MLX))

INCS			=	./include/


all:	$(NAME)

$(NAME):	$(OBJS)
	make -s -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(MLXS) -lX11 -lXext -o $(NAME) -I $(INCS)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.cpp
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

clean:
	rm -rf $(OBJ_PATH)
	make -sC $(MLX_PATH) clean

fclean:
	rm -rf $(OBJ_PATH)
	rm -f $(NAME)
	make -sC $(MLX_PATH) clean

re: fclean all
