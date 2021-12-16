# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shaas <shaas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 11:26:14 by shaas             #+#    #+#              #
#    Updated: 2021/12/16 21:10:22 by shaas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

SRC := my_code/so_long.c my_code/error_message.c

OBJ := $(SRC:.c=.o)

MAP := 0

# check if mac or linux #
OS := $(shell uname)

ifeq ($(OS),Darwin)
	COMP1 := gcc -Wall -Wextra -Werror -c
	COMP2 := gcc -Wall -Wextra -Werror $(OBJ) -Lmlx_mac -lmlx -framework OpenGL \
	-framework AppKit -o $(NAME)
else # doesnt work!!!!
	COMP := gcc -Wall -Wextra -Werror -l/usr/include -lmlx -O3 -c $(SRC) \
	-o $(NAME) && gcc -Wall -Wextra -Werror $(NAME) -Lmlx_linux -lmlx -L/usr/lib \
	-lmlx_linux -lXext -lX11 -lm -lz
endif

CODE_PATH := my_code/

all: $(NAME)

%.o: %.c
	$(COMP1) $< -o $@

$(NAME): $(OBJ)
	$(COMP2)

exec:
	@./$(NAME) $(MAP)

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all
