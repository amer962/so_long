NAME = so_long
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = mlx_linux
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I. -I$(MLX_DIR)
RM = rm -f

SRC = so_long.c error_map.c load.c widthandheight.c keyhook.c find_player.c \
		count_collectibles.c close.c filecheck.c init.c
OBJ = $(SRC:.c=.o)

MLX_LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -ldl 

all: ${LIBFT} ${NAME}

${LIBFT}: 
	${MAKE} -C ${LIBFT_DIR}

${NAME}: ${OBJ} ${LIBFT}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ} -L${LIBFT_DIR} -lft $(MLX_LIBS)

clean:
	${RM} ${OBJ}
	${MAKE} -C ${LIBFT_DIR} clean

fclean: clean
	${RM} ${NAME}
	${MAKE} -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all clean fclean re
