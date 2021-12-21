# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shaas <shaas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 11:26:14 by shaas             #+#    #+#              #
#    Updated: 2021/12/21 16:49:35 by shaas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# defines #
NAME := so_long

SRC := my_code/so_long.c my_code/error_message.c
#SRC := dumb_projects/make_a_bi_uebergang_with_mlx.c

OBJ := $(SRC:.c=.o)

PRINT_SYSTEM = 0

CODE_DIR := my_code/

MAP := 1

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

# check if mac or linux, compile mlx accordingly #
OS := $(shell uname)

ifeq ($(OS), Darwin)
	MLX_DIR = mlx_mac
	MLX = $(MLX_DIR)/libmlx.a
	COMP1 := gcc -Wall -Wextra -Werror -c
	COMP2 := gcc -Wall -Wextra -Werror $(OBJ) $(LIBFT) $(MLX) -Lmlx_mac -lmlx -framework OpenGL \
	-framework AppKit -o $(NAME)
endif
ifeq ($(OS), Linux)
	MLX_DIR = mlx_linux
	MLX = $(MLX_DIR)/libmlx.a
	COMP1 := gcc -Wall -Wextra -Werror -l/usr/include -lmlx -O3 -c # not sure if we need extra stuff?? 
	COMP2 := gcc -Wall -Wextra -Werror $(OBJ) $(LIBFT) $(MLX) -Lmlx_linux -lmlx -L/usr/lib \
	-lmlx -lXext -lX11 -lm -lz -o $(NAME)
endif


# rules #
all: $(NAME)

%.o: %.c
	$(COMP1) $< -o $@

$(NAME): print_system mlx libft $(OBJ)
	@printf $(YELLOW)"*--------object files created!---------*\n\n"$(RESET)
	$(COMP2)
	@printf $(LIGHTGREEN)"*--------executable created!-----------*\n\n"$(RESET)

# print out which system we're on, will only be executed once \
	even if called multiple times
print_system:
ifeq ($(PRINT_SYSTEM), 0)
	$(eval PRINT_SYSTEM = 1)
	@printf $(DARKGRAY)$(ITALIC)$(UNDERLINED)"We're on $(OS)\n\n"$(RESET)
endif

# rule for running program
exec: print_system
	@printf $(MAGENTA)"*--------executing program!------------*\n\n"$(RESET)
	./$(NAME) $(MAP)

mlx: print_system
	@printf $(LIGHTBLUE)"*--------checking mlx...---------------*\n\n"$(RESET)
	@make -C $(MLX_DIR) # need to check if works for mac

libft: print_system
	@printf $(LIGHTBLUE)"*--------checking libft...-------------*\n\n"$(RESET)
	@make -C $(LIBFT_DIR)

clean: print_system
	rm -fr $(OBJ)
	@printf $(RED)"*--------object files removed!---------*\n\n"$(RESET)

fclean: clean
	rm -fr $(NAME)
	@printf $(RED)"*--------$(NAME) removed!--------------*\n\n"$(RESET)

re: fclean all

# text modifiers #
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

BOLD = "\e[1m"

ITALIC = "\e[3m"

UNDERLINED = "\e[4m"

RESET = "\e[0m"
