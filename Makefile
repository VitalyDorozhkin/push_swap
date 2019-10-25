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

SRC			=	push_swap \
				print \
				funcs1 \
				funcs2

OBJ			= $(addprefix $(OBJ_PATH), $(addsuffix .o, $(SRC)))

SRC_PATH	= src/

OBJ_PATH	= .obj/

LIBFT = ./libft

LIBFT_FLAGS	= -L $(LIBFT) -I $(LIBFT)/include -lft

HEADER = ./include

LIBFT_HEADER = ./libft/include


	
all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) -I$(HEADER) $(LIBFT_FLAGS) -o $(NAME)
	

$(OBJ) : $(OBJ_PATH)%.o : $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -I$(LIBFT_HEADER) -I$(HEADER) -o $@ -c $<



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
