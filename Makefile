# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pparalax <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 16:59:28 by pparalax          #+#    #+#              #
#    Updated: 2019/09/06 16:59:33 by pparalax         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CFLAGS		= #-Wall -Wextra -Werror

CC			= gcc

SRC			=	push_swap.c \
				funcs1.c \
				funcs2.c

OBJ			= push_swap.o \
				funcs1.o \
				funcs2.o

LIBFT = ./libft

LIBFT_FLAGS	= -L $(LIBFT) -I $(LIBFT)/include -lft

HEADER = -I./include

LIBFT_HEADER = -I./libft/include

all: $(NAME)



$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(HEADER) $(LIBFT_FLAGS) -o $(NAME)



$(OBJ) : %.o : %.c
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT_HEADER) $(HEADER) -o $@ -c $<



clean:
	make fclean -C $(LIBFT)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run:
	./push_swap $$(./rearg 100)

run500:
	./push_swap $$(./rearg 500)

.PHONY: all clean fclean re
