# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/22 12:21:57 by jmatute-          #+#    #+#              #
#    Updated: 2021/11/01 04:30:44 by jmatute-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=  fill_stack.c errors_args.c check_not_repite.c

LIBFT_DIR	= libft/

OBJS	= ${SRCS:.c=.o}

NAME	= pushswap

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address

.c.o: ${SRCS}
			${CC} -g3 -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} pushswap.h Makefile
			@make -sC ${LIBFT_DIR}
			@cp ./libft/libft.a .
			${CC} -g3 libft.a ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			@make -sC ${LIBFT_DIR} clean
			${RM} ${OBJS} libft.a

fclean:		clean
			@make -sC ${LIBFT_DIR} fclean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re