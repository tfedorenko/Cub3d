NAME = cub3d

SRC_DIR = ./src/

SRC =	main.c \
			set_info.c \
			error_check.c \
			set_identifier_1.c \
			set_rgb.c \
			set_identifier_utils.c \
			check_identifier.c \
			check_compass.c \
			set_texture.c \
			utils.c \
			debug_utils.c \
			init.c \
			exit_and_close.c \
			drawing_utils.c \

OBJ = ${addprefix ${SRC_DIR}, ${SRC:.c=.o}}

GNL_DIR = ./gnl/
GNL =	get_next_line.c \
		get_next_line_utils.c \

GNL_OBJ = ${addprefix ${GNL_DIR}, ${GNL}}

LIBFT_DIR = ./libft
LIBFT_PATH = ${LIBFT_DIR}/libft.a

MLX_DIR=./mlx/
INCLMLX=-L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

DEBUG = -fsanitize=address -g
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCL= -I ./includes
INCLFT = -L ${LIBFT_DIR} -lft

RM = rm -f
all:${NAME}

$(LIBFT_PATH):
	@make all -C -s $(LIBFT_DIR)



$(NAME): $(OBJ) $(GNL_OBJS) $(LIBFT_PATH)
	@make all -sC $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(GNL_OBJ) $(INCL) $(DEBUG) $(INCLFT) $(INCLMLX) -o ${NAME}
	@echo "Brr brrr compiling ..."


clean:
		@${RM} ${OBJ}
		@make clean -sC ${LIBFT_DIR}
		@echo "cleaning up .o files ..."

fclean: clean
		@${RM} ${OBJ} ${NAME}
		@echo "rrrremoving everything..."

re:	fclean all

.PHONY: all clean flcean re