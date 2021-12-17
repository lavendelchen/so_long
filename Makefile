# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shaas <shaas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 11:26:14 by shaas             #+#    #+#              #
#    Updated: 2021/12/17 02:25:28 by shaas            ###   ########.fr        #
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

# rules #
all: $(NAME)

%.o: %.c
	$(COMP1) $< -o $@

$(NAME): $(OBJ)
	@printf $(YELLOW)"*--------object files created!---------*\n"$(CL_RESET)
	$(COMP2)
	@printf $(LIGHTGREEN)"*--------executable created!-----------*\n"$(CL_RESET)

exec:
	@printf $(MAGENTA)"*--------executing program!------------*\n"$(CL_RESET)
	./$(NAME) $(MAP)

clean:
	rm -fr $(OBJ)
	@printf $(RED)"*--------object files removed!---------*\n"$(CL_RESET)

fclean: clean
	rm -fr $(NAME)
	@printf $(RED)"*--------$(NAME) removed!--------------*\n"$(CL_RESET)

re: fclean all

# text colours #
RED = "\e[31m"

GREEN = "\e[32m"

YELLOW = "\e[33m"

BLUE = "\e[34m"

MAGENTA = "\e[35m"

CYAN = "\e[36m"

LIGHTGRAY = "\e[37m"

DARKGRAY = "\e[90m"

LIGHTRED = "\e[91m"

LIGHTGREEN = "\e[92m"

LIGHTYELLOW = "\e[93m"

LIGHTBLUE = "\e[94m"

LIGHTMAGENTA = "\e[95m"

LIGHTCYAN = "\e[96m"

RED_BG = "\e[41m"

GREEN_BG = "\e[42m"

YELLOW_BG = "\e[43m"

BLUE_BG = "\e[44m"

MAGENTA_BG = "\e[45m"

CYAN_BG = "\e[46m"

LIGHTGRAY_BG = "\e[47m"

DARKGRAY_BG = "\e[100m"

LIGHTRED_BG = "\e[101m"

LIGHTGREEN_BG = "\e[102m"

LIGHTYELLOW_BG = "\e[103m"

LIGHTBLUE_BG = "\e[104m"

LIGHTMAGENTA_BG = "\e[105m"

LIGHTCYAN_BG = "\e[106m"

CL_RESET = "\e[0m"
