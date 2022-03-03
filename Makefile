# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 21:12:11 by jefernan          #+#    #+#              #
#    Updated: 2022/03/02 23:21:48 by jefernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
NAME_BONUS	= so_long_bonus
CC			= clang
RM			= rm -rf
MKDIR		= mkdir -p

CFLAGS	=	-Wall -Wextra -Werror -g3
MLXFLAGS = -Imlx -lX11 -lXext

MINILIBX_PATH = ./libs/mlx
MINILIBX = ${MINILIBX_PATH}/libmlx_Linux.a

LIBFT_PATH = ./libs/libft
LIBFT = ${LIBFT_PATH}/libft.a

HEADER		 = $(SRCS_DIR)/so_long.h
HEADER_BONUS = ${BONUS_DIR}/so_long_bonus.h

SRCS		=	so_long.c open_file_map.c check_map.c close_game.c \
				start_game.c put_image.c key_hook.c start.c ft_print_d_i.c \
				ft_print_str.c ft_printf.c \

SRCS_BONUS	= 	so_long_bonus.c open_file_map_bonus.c check_map_bonus.c \
				close_game_bonus.c start_game_bonus.c put_image_bonus.c \
				key_hook_bonus.c start_bonus.c ft_print_d_i_bonus.c \
				ft_printf_bonus.c ft_print_str_bonus.c put_steps_bonus.c \
				move_up_bonus.c move_left_bonus.c move_right_bonus.c \
				move_down_bonus.c put_enemy_bonus.c animation_bonus.c

SRCS_DIR  = srcs
BONUS_DIR = srcs_bonus

OBJ_DIR	 =	obj

SOURCES			=	$(addprefix $(SRCS_DIR)/, $(SRCS))
SOURCES_BONUS	=	$(addprefix $(BONUS_DIR)/, $(SRCS_BONUS))
	

OBJECTS			=	$(SOURCES:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJECTS_BONUS	=	$(SOURCES_BONUS:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:		$(SRCS_DIR)/%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o:		$(BONUS_DIR)/%.c $(HEADER_BONUS)
					$(CC) $(CFLAGS) -c $< -o $@

all:		${NAME}

bonus:		${NAME_BONUS}

${NAME}:	${OBJ_DIR} ${LIBFT} $(HEADER) ${OBJECTS} ${MINILIBX}
				${CC} ${CFLAGS} ${SOURCES} ${MINILIBX} ${LIBFT} \
				${MLXFLAGS} -o ${NAME}

${NAME_BONUS}:	${OBJ_DIR} ${LIBFT} $(HEADER_BONUS) ${OBJECTS_BONUS} \
				${MINILIBX}
					${CC} ${CFLAGS} ${SOURCES_BONUS} ${MINILIBX} ${LIBFT} \
					${MLXFLAGS} -o ${NAME_BONUS}

${LIBFT}:
				make -C ${LIBFT_PATH}

$(MINILIBX):
				make -C ${MINILIBX_PATH}			

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

clean:
			make clean -C ${LIBFT_PATH}
			${RM} ${OBJ_DIR}
			

fclean:		clean
				make fclean -C ${LIBFT_PATH}
				${RM} ${NAME} ${NAME_BONUS}
			
re:			fclean all

.PHONY: 	all clean fclean re libft minilibx