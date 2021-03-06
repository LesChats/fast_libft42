# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaudot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/05 14:49:33 by abaudot           #+#    #+#              #
#    Updated: 2021/01/05 14:50:42 by abaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
	   ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c\
	   ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
	   ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c\
	   ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
	   ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS = ${SRCS:.c=.o}

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
		ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUSOBJS = ${BONUS:.c=.o}

CC        = cc
RM        = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all:    ${NAME}

clean:
	${RM} ${OBJS} ${BONUSOBJS}

fclean:    clean
	${RM} ${NAME}

re:        fclean all

bonus: ${OBJS} ${BONUSOBJS}
	ar rcs ${NAME} ${OBJS} ${BONUSOBJS}

so: all
		gcc -o libft.so -shared -fPIC $(OBJS)
.PHONY : all clean fclean re bonus
