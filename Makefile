# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 21:12:11 by jefernan          #+#    #+#              #
#    Updated: 2022/02/07 22:27:12 by jefernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	clang
RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror
MLXFLAGS = -Imlx -lX11 -lXext

MINILIBX_PATH = ./libs/mlx
MINILIBX = ${MINILIBX_PATH}/libmlx_Linux.a

LIBFT_PATH = ./libs/libft
LIBFT = ${LIBFT_PATH}/libft.a

SRCS	=	

SRCS_DIR = srcs
OBJ_DIR = objs

HEADER = ${SRCS_DIR}/so_long.h

SOURCES = $(addprefix $(SRCS_DIR)/, $(SRCS))

OBJS	= $(SOURCES:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)



${OBJ_DIR}/%.o:		${SRCS_DIR}/%.c ${HEADER}
						${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJ_DIR} ${LIBFT} $(MINILIBX) ${OBJS} ${HEADER}
			${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MINILIBX} \
			${MLXFLAGS} -o ${NAME}

${LIBFT}:
				make -C ${LIBFT_PATH}

$(MINILIBX):
				make -C ${MINILIBX_PATH}

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

clean:
			make clean -C ${LIBFT_PATH}
			make clean -C ${MINILIBX_PATH}
			${RM} ${OBJ_DIR}
			

fclean:		clean
				make fclean -C ${LIBFT_PATH}
				${RM} ${NAME}
			
re:			fclean all

.PHONY: 	all clean fclean re libft minilibx