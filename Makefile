# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shaas <shaas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 11:26:14 by shaas             #+#    #+#              #
#    Updated: 2021/12/14 20:20:38 by shaas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

COMP = gcc -Wall -Wextra -Werror

CODE_PATH = my_code/

O_DIR = objects

C_FILES = my_code/so_long.c my_code/error_message.c

O_FILES := $(addprefix $(O_DIR)/, $(C_FILES:.c=.o))

BONUS_FILES =

BONUS_O_FILES =  $(BONUS_FILES:.c=.o)

all: $(NAME) bonus

comp:
	$(COMP) $(C_FILES)

$(NAME): comp
	ar rc $(NAME) $(O_FILES)

clean:
	rm -f $(O_FILES) $(BONUS_O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonuscomp:
	$(COMP) $(BONUS_FILES)

bonus: bonuscomp
	ar rc $(NAME) $(BONUS_O_FILES)
