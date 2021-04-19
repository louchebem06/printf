# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 22:32:25 by bledda            #+#    #+#              #
#    Updated: 2021/04/19 15:01:21 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	= ft_printf.c \
			ft_itoh.c \
			ft_strrev.c \
			ft_strtolower.c \
			ft_strtoupper.c \
			ft_before_data.c \
			ft_isconvert.c \
			ft_putnstr.c \
			ft_strchrintab.c \
			ft_strreplace.c \
			ft_flagsjoin.c \
			ft_uitoa.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS  = -Wall -Wextra -Werror
RM		= rm -f
LIBFT	= cd libft/ && make

$(NAME):	libft ${OBJS}
			ar -rcs ${NAME} ${OBJS}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

clean:
			${RM} ${OBJS}
			${LIBFT} clean

fclean:		clean
			rm $(NAME)
			${LIBFT} fclean

re:			fclean all

libft:
			${LIBFT} bonus
			cp libft/libft.a $(NAME)

.PHONY: $(NAME) all clean fclean re libft