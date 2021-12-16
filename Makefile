# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shaas <shaas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 11:26:14 by shaas             #+#    #+#              #
#    Updated: 2021/12/16 20:44:49 by shaas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

SRC := my_code/so_long.c my_code/error_message.c

OBJ := $(C_FILES:.c=.o)

OS := $(shell uname)

ifeq ($(OS),Darwin)
	COMP := gcc -Wall -Wextra -Werror -Lmlx_mac -lmlx -framework OpenGL \
	-framework AppKit $(SRC) -o $(NAME)
else # doesnt work!!!!
	COMP := gcc -Wall -Wextra -Werror -l/usr/include -lmlx_linux -O3 -c $(SRC) \
	-o $(NAME) && gcc -Wall -Wextra -Werror $(NAME) -Lmlx_linux -lmlx_linux -L/usr/lib \
	-lmlx_linux -lXext -lX11 -lm -lz
endif

CODE_PATH := my_code/

O_DIR := objects

all: $(NAME)

trying:
	$(COMP)

%.o: %.c
	$(COMP) $<

$(NAME): comp
	ar rc $(NAME) $(O_FILES)

clean:
	rm -f $(O_FILES) $(BONUS_O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
