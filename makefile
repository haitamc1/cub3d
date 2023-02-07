NAME = cub3d

CC = gcc

M_INCL_DIR = include/

M_INCLUDE_NAME = cub3d

M_SRC_PRIME_DIR = src/

M_SRC_PARSE_DIR = src/parse_map/

M_SRC_DRAW_DIR = src/draw/

FALGS = -Wall -Wextra -fsanitize=address -g#-Werror #

M_SRC_PARSE_NAME = utils utils1 utils2 loading_data parse_resource parse_map #ft_split ft_atoi  ft_isdigit

M_SRC_DRAW_NAME = 

M_SRC_PRIME_NAME = control init_cub3d  main draw line ray  wall move intersection debug

BUILD_DIR = build/

M_SRC_DIR  = src/

LIBS = $(LIB_FT)libft.a $(LIB_GNL)libgnl.a

LIB_FT = lib/libft/

LIB_GNL = lib/get_next_line/

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
MLX_FLAGS_LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

# Header files
M_INCLUDE = $(addsuffix .h, $(M_INCLUDE_NAME))
M_INCLUDE_PATH = $(addprefix $(M_INCL_DIR), $(M_INCLUDE))

# Source files
M_SRC_PRIME_PATH = $(addprefix $(M_SRC_PRIME_DIR), $(M_SRC_PRIME_NAME))
M_SRC_PARSE_PATH = $(addprefix $(M_SRC_PARSE_DIR), $(M_SRC_PARSE_NAME))
M_SRC_EXEC_PATH = $(addprefix $(M_SRC_EXEC_DIR), $(M_SRC_EXEC_NAME))
M_SRC_PATH = $(M_SRC_PARSE_PATH) $(M_SRC_PRIME_PATH) $(M_SRC_EXEC_PATH)
M_SRC_NAME = $(M_SRC_PARSE_NAME) $(M_SRC_PRIME_NAME) $(M_SRC_EXEC_NAME)
M_SRC = $(addsuffix .c, $(M_SRC_PATH))

# Object files
M_OBJ = $(M_SRC:%=$(BUILD_DIR)%.o)


all : $(NAME)
	@echo everything is in order...

$(NAME) : $(M_OBJ) $(M_INCLUDE_PATH)
	make bonus -C $(LIB_FT)
	make bonus -C $(LIB_GNL)
	$(CC) $(MLX_FLAGS) $(FALGS) $(LFLAGS)  $(M_OBJ) $(LIBS) -o $(NAME)

linux : $(M_OBJ) $(M_INCLUDE_PATH)
	make bonus -C $(LIB_FT)
	make bonus -C $(LIB_GNL)
	$(CC) $(M_OBJ) $(MLX_FLAGS_LINUX) $(FALGS) $(LFLAGS) $(LIBS) -o $(NAME)

$(BUILD_DIR)%.c.o : %.c $(M_INCLUDE_PATH)
	@mkdir -p $(dir $@)
	$(CC) $(FALGS) $(IFLAGS) -c $< -o $@

clean :
	@make clean -C $(LIB_GNL)
	@make clean -C $(LIB_FT)
	rm -rf $(BUILD_DIR)

fclean : clean
	@make fclean -C $(LIB_FT)
	rm -rf $(NAME)

re : fclean all

.PHONY: all re clean fclean
