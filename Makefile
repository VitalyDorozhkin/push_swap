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

NAME	= push_swap
NAME_CHECKER	= checker

CFLAGS		= -Wall -Wextra -Werror

CC			= gcc

SRC			=	\
				sort1 \
				sort2 \
				helpers1 \
				helpers2 \
				input \
				print \
				funcs1 \
				funcs2

OBJ			= $(addprefix $(OBJ_PATH), $(addsuffix .o, $(SRC)))

PUSH_SWAP_OBJ = $(addprefix $(OBJ_PATH), $(addsuffix .o, $(NAME)))

CHECKER_OBJ = $(addprefix $(OBJ_PATH), $(addsuffix .o, $(NAME_CHECKER)))

OBJ_ALL		= $(OBJ)
OBJ_ALL += $(PUSH_SWAP_OBJ)
OBJ_ALL += $(CHECKER_OBJ)

SRC_PATH	= src/

OBJ_PATH	= .obj/

LIBFT = ./libft

LIBFT_FLAGS	= -L $(LIBFT) -I $(LIBFT)/include -lft

HEADER = ./include

LIBFT_HEADER = ./libft/include

all: liba $(NAME)

liba:
	make -C ./libft

$(NAME): $(OBJ_ALL) libft/libft.a
	$(CC) $(CFLAGS) $(OBJ) $(PUSH_SWAP_OBJ) -I$(HEADER) $(LIBFT_FLAGS) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJ) $(CHECKER_OBJ) -I$(HEADER) $(LIBFT_FLAGS) -o $(NAME_CHECKER)

$(OBJ_ALL) : $(OBJ_PATH)%.o : $(SRC_PATH)%.c include/push_swap.h
	$(CC) $(CFLAGS) -I$(LIBFT_HEADER) -I$(HEADER) -o $@ -c $<

clean:
	make fclean -C $(LIBFT)
	rm -f $(OBJ_ALL)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_CHECKER)

re: fclean all

run:
	./push_swap $$(./rearg 100)

run500:
	./push_swap $$(./rearg 500)

.PHONY: all clean fclean re
