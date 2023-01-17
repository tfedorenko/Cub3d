NAME = cub3D
BONUS_NAME = cub3D_bonus
SRC_DIR = ./src/
BONUS_DIR = ./src_bonus/
COLOR = '\033[1;36m'
NC = '\033[0m'
SRC =	main.c \
			allowed_characters.c \
			set_info.c \
			error_check.c \
			set_identifier_1.c \
			set_rgb.c \
			set_identifier_utils.c \
			check_identifier.c \
			check_compass.c \
			set_texture.c \
			set_minimap.c \
			check_map_1.c \
			check_map_2.c \
			check_map_3.c \
			valid_player.c \
			map_start.c \
			remove_nl.c \
			utils_1.c \
			utils_2.c \
			debug_utils.c \
			init.c \
			exit_and_close.c \
			drawing_utils.c \
			collisions.c \
			texturing.c \
			ray_handling_and_dda.c \
			key_events_handling.c \

OBJ = ${addprefix ${SRC_DIR}, ${SRC:.c=.o}}

BONUS_SRC =	main_bonus.c \
			allowed_characters.c \
			set_info.c \
			error_check.c \
			set_identifier_1.c \
			set_rgb.c \
			set_identifier_utils.c \
			check_identifier.c \
			check_compass.c \
			set_texture.c \
			set_minimap.c \
			check_map_1.c \
			check_map_2.c \
			check_map_3.c \
			valid_player.c \
			map_start.c \
			remove_nl.c \
			utils_1.c \
			utils_2.c \
			keyinput.c \
			minimap_bonus.c \
			debug_utils.c \
			init.c \
			exit_and_close.c \
			drawing_utils.c \
			collisions.c \
			texturing.c \
			ray_handling_and_dda.c \
			key_events_handling.c \
			extra_key_bonus.c \
			rain_bonus.c \

BONUS_OBJ = ${addprefix ${BONUS_DIR}, ${BONUS_SRC:.c=.o}}

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
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
INCL= -I ./includes
INCLFT = -L ${LIBFT_DIR} -lft

RM = rm -f
all:${NAME}

$(LIBFT_PATH):
	@make all -sC $(LIBFT_DIR)


$(NAME): $(OBJ) $(GNL_OBJS) $(LIBFT_PATH)
	@make all -sC $(LIBFT_DIR)
	@make  -sC ${MLX_DIR}
	@$(CC) $(CFLAGS) $(OBJ) $(GNL_OBJ) $(INCL) $(INCLFT) $(INCLMLX) -o ${NAME}
	@echo ${COLOR}"Brr brrr compiling ..."${NC}

$(BONUS_NAME): $(BONUS_OBJ) $(GNL_OBJS) $(LIBFT_PATH)
	@make all -sC $(LIBFT_DIR)
	@make  -sC ${MLX_DIR}
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(GNL_OBJ) $(INCL) $(DEBUG) $(INCLFT) $(INCLMLX) -o ${BONUS_NAME}
	@echo ${COLOR}"Brr brrr compiling ..."${NC}


clean:
		@${RM} ${BONUS_OBJ} ${NAME}\
		@${RM} ${OBJ} ${NAME}
		@make clean -sC ${LIBFT_DIR}
		@echo "cleaning up .o files ...🧹"${NC}

bonus: $(BONUS_NAME)

fclean: clean
			@${RM} ${OBJ} ${NAME} ${NAME}
		@${RM} ${BONUS_OBJ} ${NAME} ${BONUS_NAME}
		@make fclean -sC ${LIBFT_DIR}
		@make clean -sC ${MLX_DIR}
		@echo '\033[1;32m' "rrrremoving everything ...☠️" ${NC}

re:	fclean all


.PHONY: all clean flcean re