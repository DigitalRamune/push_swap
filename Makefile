# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/22 16:26:23 by inaciri           #+#    #+#              #
#    Updated: 2026/03/12 12:33:18 by inaciri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
	operations/ft_rotate.c \
	ft_find.c \
	operations/ft_swap.c \
	ft_isdigit.c \
	ft_detect.c \
	libft/ft_strdup.c \
	ft_disorder.c \
	libft/ft_strncmp.c \
	libft/ft_strlen.c \
	libft/ft_split.c \
	libft/ft_lstnew_bonus.c \
	libft/ft_lstadd_front_bonus.c \
	libft/ft_atoi.c \
	libft/ft_lstlast_bonus.c \
	operations/ft_push.c \
	libft/ft_lstsize_bonus.c\
	simple/ft_simple_alg.c \
	medium/ft_medium_alg.c \
	complex/ft_radix.c \
	ft_choice.c \
	ft_create_stack.c

OBJS := ${SRCS:.c=.o}

NAME = push_swap

all: ${NAME}

${NAME}: ${OBJS}
	@echo Compiling...
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@
	
run:
	./$(NAME) --complex $$(shuf -i 1-10000 -n 100)
clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY: all clean fclean re run