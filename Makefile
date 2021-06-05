# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 22:32:25 by bledda            #+#    #+#              #
#    Updated: 2021/06/05 15:49:31 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

HEADER_FILE = header/ft_printf.h

FOLDER		= src/

SRCS		= ft_printf.c \
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
			ft_uitoa.c \
			ft_flags.c \
			ft_check_percent.c \
			ft_check_c.c \
			ft_check_s.c \
			ft_check_p.c \
			ft_check_di.c \
			ft_check_u.c \
			ft_check_xX.c \
			ft_flags_di_utils.c \
			ft_flags_di_utils2.c \
			ft_flags_di_utils3.c \
			ft_flags_di_utils4.c

SRC			= $(addprefix ${FOLDER},${SRCS})

OBJS		= ${SRC:.c=.o}

LIBFT		= cd libft/ && make

CC			= gcc
CFLAGS  	= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar -rcs

$(NAME):	libft ${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

%.o: %.c	$(HEADER_FILE)
			$(CC) -c $(CFLAGS) -o $@ $<

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

.PHONY:		all clean fclean re libft
