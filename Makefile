# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/22 12:21:57 by jmatute-          #+#    #+#              #
#    Updated: 2021/11/26 12:46:18 by jmatute-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=  fill_stack.c errors_args.c check_not_repite.c pushswap.c rules_ss.c rules_rr.c rules_rrr.c rules_push.c  moves_depending_on_size.c move_when_size_five.c size_chunks.c holds.c

LIBFT_DIR	= libft/

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address

.c.o: ${SRCS}
			${CC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} pushswap.h Makefile
			@make -sC ${LIBFT_DIR}
			@cp ./libft/libft.a .
			${CC}  libft.a ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			@make -sC ${LIBFT_DIR} clean
			${RM} ${OBJS} libft.a

fclean:		clean
			@make -sC ${LIBFT_DIR} fclean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re