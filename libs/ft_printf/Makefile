# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 10:34:38 by jefernan          #+#    #+#              #
#    Updated: 2022/02/10 00:44:41 by jefernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar
ARFLAGS	=	rcs
LIBFT = ../libft/libft.a

SRCS	=	ft_printf.c ft_print_d_i.c ft_print_hex.c ft_print_ptr.c \
			ft_print_str.c ft_print_unsigned.c

OBJS	= ${SRCS:.c=.o}

RM		=	rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} ${LIBFT}
			cp ${LIBFT} $(NAME)
			${AR} ${ARFLAGS} ${NAME} ${OBJS}

${LIBFT}:
			make -C ./libft/

clean:
			${RM} ${OBJS}
			make clean -C ../libft/

fclean:		clean
			${RM} ${NAME}
			make fclean -C ../libft/

re:			fclean all

.PHONY: 	all clean fclean re