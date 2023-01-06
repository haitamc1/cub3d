NAME = cub3d 

HEADER = cub3d.h

GNL = get_next_line.c get_next_line_utils.c 

SRC = cub3d.c keys.c utils.c utils1.c ft_split.c ft_atoi.c loading_data.c ft_isdigit.c
	
OBJ = $(SRC:.c=.o)

GNLOBJ = $(GNL:.c=.o)


FLAGS = -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	cc -c $< 

$(NAME): $(OBJ) $(GNLOBJ)
	cc $(FLAGS) $(GNLOBJ) $(OBJ) -o $(NAME) 

	

all : ${NAME}

clean :
	rm -rf ${OBJ} $(GNLOBJ)


fclean : clean
	rm -rf ${NAME}


re : fclean all

.PHONY: all fclean clean re
