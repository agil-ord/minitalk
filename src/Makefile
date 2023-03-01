# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 12:57:21 by agil-ord          #+#    #+#              #
#    Updated: 2022/11/26 21:33:46 by agil-ord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ITS IS MAKEFILE MINITALK

INCLUDE = -I ./libft/includes -I ./includes
 
NAME	=	server

DIR_MINITALK = ./src

SRC_MINITALK =	client.c server.c

SRCS	=	${addprefix ${DIR_MINITALK}/,${SRC_MINITALK}}

#OBJS	=	${addprefix ${DIR_MINITALK}/,${SRC_MINITALK:.c=.o}}

LIBFT_DIR	=	./libft

AR		=	ar	-crs ${INCLUDE}

CC			=	gcc

CFLAG		=	-Wall -Werror -Wextra ${INCLUDE}

RM			=	rm -f

all: ${NAME}

${NAME}: 
		@make -C ${LIBFT_DIR}
#		@cp ${LIBFT_DIR}/libft.a ${NAME}
		${CC} ${CFLAG} ./src/client.c ${LIBFT_DIR}/libft.a -o client
		${CC} ${CFLAG} ./src/server.c ${LIBFT_DIR}/libft.a -o ${NAME}

clean:	
		@make clean -C ${LIBFT_DIR} 

fclean:	clean
		@make fclean -C ${LIBFT_DIR} 
		${RM} ${NAME} client
		
re:	fclean all

.PHONY: all	clean fclean re
